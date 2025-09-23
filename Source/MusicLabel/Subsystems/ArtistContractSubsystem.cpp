#include "ArtistContractSubsystem.h"

#include "Engine/GameInstance.h"
#include "EventSubsystem.h"
#include "LabelManager/Public/LabelDataAssets.h"

FArtistContract::FArtistContract()
    : Status(EContractStatus::Negotiating)
    , SignedDate(FDateTime::MinValue())
    , RecordsDelivered(0)
{
}

bool UArtistContractSubsystem::ApplyContractInternal(UArtistAsset* Artist, const FContractTerms& Terms, const TCHAR* Context)
{
    if (!Artist)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s called with invalid artist."), Context);
        return false;
    }

    if (FArtistContract* ExistingContract = FindContract(Artist))
    {
        // Only allow re-signing once a previous contract has concluded.
        if (ExistingContract->Status == EContractStatus::Completed || ExistingContract->Status == EContractStatus::Terminated)
        {
            ExistingContract->Terms = Terms;
            ExistingContract->Status = EContractStatus::Signed;
            ExistingContract->SignedDate = FDateTime::UtcNow();
            ExistingContract->RecordsDelivered = 0;
            ExistingContract->Artist = Artist;
            return true;
        }

        UE_LOG(LogTemp, Warning, TEXT("Artist %s already has an active contract."), *Artist->GetName());
        return false;
    }

    FArtistContract NewContract;
    NewContract.Artist = Artist;
    NewContract.Terms = Terms;
    NewContract.Status = EContractStatus::Signed;
    NewContract.SignedDate = FDateTime::UtcNow();
    NewContract.RecordsDelivered = 0;

    ArtistContracts.Add(NewContract);
    return true;
}

bool UArtistContractSubsystem::SignContract(UArtistAsset* Artist,FContractTerms Terms)
{
    const bool bSigned = ApplyContractInternal(Artist, Terms, TEXT("SignContract"));
    if (bSigned)
    {
        NotifyArtistSigned(Artist, Terms);
    }

    return bSigned;
}

bool UArtistContractSubsystem::SignContractWithTerms(UArtistAsset* Artist, const FContractTerms& Terms)
{
    const bool bSigned = ApplyContractInternal(Artist, Terms, TEXT("SignContractWithTerms"));
    if (bSigned)
    {
        NotifyArtistSigned(Artist, Terms);
    }

    return bSigned;
}

bool UArtistContractSubsystem::UpdateContractStatus(UArtistAsset* Artist, EContractStatus NewStatus)
{
    if (FArtistContract* Contract = FindContract(Artist))
    {
        Contract->Status = NewStatus;

        if (NewStatus == EContractStatus::Signed && Contract->SignedDate == FDateTime::MinValue())
        {
            Contract->SignedDate = FDateTime::UtcNow();
        }
        return true;
    }

    UE_LOG(LogTemp, Warning, TEXT("UpdateContractStatus failed. No contract found for artist."));
    return false;
}

bool UArtistContractSubsystem::MarkRecordDelivered(UArtistAsset* Artist)
{
    if (FArtistContract* Contract = FindContract(Artist))
    {
        Contract->RecordsDelivered = FMath::Max(Contract->RecordsDelivered + 1, 0);

        const int32 RequiredRecords = Contract->Terms.GetRecordsNumber();
        if (RequiredRecords > 0 && Contract->RecordsDelivered >= RequiredRecords)
        {
            Contract->Status = EContractStatus::Completed;
        }
        else if (Contract->Status == EContractStatus::Signed)
        {
            Contract->Status = EContractStatus::Active;
        }

        return true;
    }

    UE_LOG(LogTemp, Warning, TEXT("MarkRecordDelivered failed. No contract found for artist."));
    return false;
}

bool UArtistContractSubsystem::IsArtistSigned(UArtistAsset* Artist) const
{
    if (const FArtistContract* Contract = FindContract(Artist))
    {
        return Contract->Status == EContractStatus::Signed || Contract->Status == EContractStatus::Active;
    }

    return false;
}

FArtistContract UArtistContractSubsystem::GetContract(UArtistAsset* Artist, bool& bFound) const
{
    if (const FArtistContract* Contract = FindContract(Artist))
    {
        bFound = true;
        return *Contract;
    }

    bFound = false;
    return FArtistContract();
}

FArtistContract* UArtistContractSubsystem::FindContract(UArtistAsset* Artist)
{
    if (!Artist)
    {
        return nullptr;
    }

    for (FArtistContract& Contract : ArtistContracts)
    {
        if (Contract.Artist.Get() == Artist)
        {
            return &Contract;
        }
    }

    return nullptr;
}

const FArtistContract* UArtistContractSubsystem::FindContract(UArtistAsset* Artist) const
{
    if (!Artist)
    {
        return nullptr;
    }

    for (const FArtistContract& Contract : ArtistContracts)
    {
        if (Contract.Artist.Get() == Artist)
        {
            return &Contract;
        }
    }

    return nullptr;
}

void UArtistContractSubsystem::NotifyArtistSigned(UArtistAsset* Artist, const FContractTerms& Terms)
{
    if (!Artist)
    {
        return;
    }

    UGameInstance* GameInstance = GetGameInstance();
    if (!GameInstance)
    {
        return;
    }

    UEventSubsystem* EventSubsystem = GameInstance->GetSubsystem<UEventSubsystem>();
    if (!EventSubsystem)
    {
        return;
    }

    FGameEvent Event;
    Event.Headline = FString::Printf(TEXT("%s Signs a Record Deal"), *Artist->GetName());
    Event.Date = FDateTime::UtcNow();
    Event.EventCategory = EEventCategory::ArtistSignedRecordDeal;


    const TArray<TSoftObjectPtr<UGenreAsset>>& Genres = Artist->GetGenreAffinity();
    TArray<FString> GenreNames;
    GenreNames.Reserve(Genres.Num());

    for (const TSoftObjectPtr<UGenreAsset>& GenrePtr : Genres)
    {
        if (const UGenreAsset* Genre = GenrePtr.Get())
        {
            GenreNames.Add(Genre->GetName());
        }
        else if (!GenrePtr.ToSoftObjectPath().IsNull())
        {
            GenreNames.Add(GenrePtr.GetAssetName());
        }
    }

    FString GenreSummary;
    if (GenreNames.Num() == 0)
    {
        GenreSummary = TEXT("their unique sound");
    }
    else if (GenreNames.Num() == 1)
    {
        GenreSummary = GenreNames[0];
    }
    else
    {
        GenreSummary = FString::Join(GenreNames, TEXT(", "));
    }

    const FArtistAttributes& Attributes = Artist->GetAttributes();
    TArray<FString> Highlights;

    if (Attributes.GetMusicality() >= 85.f)
    {
        Highlights.Add(TEXT("fantastic singer"));
    }
    else if (Attributes.GetMusicality() >= 70.f)
    {
        Highlights.Add(TEXT("strong vocalist"));
    }

    if (Attributes.GetCreativity() >= 85.f)
    {
        Highlights.Add(TEXT("brilliant songwriter"));
    }
    else if (Attributes.GetCreativity() >= 70.f)
    {
        Highlights.Add(TEXT("good songwriter"));
    }

    if (Attributes.GetCharisma() >= 85.f)
    {
        Highlights.Add(TEXT("captivating performer"));
    }
    else if (Attributes.GetMarketAppeal() >= 85.f)
    {
        Highlights.Add(TEXT("crowd favorite"));
    }

    FString HighlightSummary;
    if (Highlights.Num() == 0)
    {
        HighlightSummary = TEXT("A promising all-around talent.");
    }
    else
    {
        TArray<FString> HighlightPhrases;
        HighlightPhrases.Reserve(Highlights.Num());
        for (const FString& Highlight : Highlights)
        {
            HighlightPhrases.Add(FString::Printf(TEXT("a %s"), *Highlight));
        }

        if (HighlightPhrases.Num() == 1)
        {
            HighlightSummary = FString::Printf(TEXT("Known for being %s."), *HighlightPhrases[0]);
        }
        else
        {
            FString Combined;
            for (int32 Index = 0; Index < HighlightPhrases.Num(); ++Index)
            {
                if (Index == 0)
                {
                    Combined += HighlightPhrases[Index];
                }
                else if (Index == HighlightPhrases.Num() - 1)
                {
                    Combined += FString::Printf(TEXT(" and %s"), *HighlightPhrases[Index]);
                }
                else
                {
                    Combined += FString::Printf(TEXT(", %s"), *HighlightPhrases[Index]);
                }
            }

            HighlightSummary = FString::Printf(TEXT("Known for being %s."), *Combined);
        }
    }

    const int32 RecordCount = FMath::Max(1, Terms.GetRecordsNumber());
    const FString DealSummary = RecordCount == 1
                                    ? TEXT("a 1-record deal")
                                    : FString::Printf(TEXT("a %d-record deal"), RecordCount);

    Event.Description = FString::Printf(
        TEXT("%s inked %s focused on %s. %s"),
        *Artist->GetName(),
        *DealSummary,
        *GenreSummary,
        *HighlightSummary);

    EventSubsystem->AddPendingEvent(Event);
}

