#include "ContentCatalogSubsystem.h"

#include "LabelManager/Public/ArtistGenerationLibrary.h"
#include "LabelManager/Public/LabelDataAssets.h"

void UContentCatalogSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    FiftiesRockArtists = UArtistGenerationLibrary::GenerateFiftiesRockArtists();
    FiftiesRockArtistIndexByName.Reset();

    for (int32 Index = 0; Index < FiftiesRockArtists.Num(); ++Index)
    {
        if (UArtistAsset* Artist = FiftiesRockArtists[Index])
        {
            const FString& ArtistName = Artist->GetName();
            if (!ArtistName.IsEmpty())
            {
                FiftiesRockArtistIndexByName.Add(FName(*ArtistName), Index);
            }
        }
    }
}

TArray<USongAsset*> UContentCatalogSubsystem::FindSongsByGenre(FName Genre) const
{
    return {};
}

UArtistAsset* UContentCatalogSubsystem::GetArtistByName(FName ArtistName) const
{
    return nullptr;
}

TArray<UArtistAsset*> UContentCatalogSubsystem::SearchArtistsByName(const FString& NameQuery) const
{
    TArray<UArtistAsset*> MatchingArtists;

    const FString TrimmedQuery = NameQuery.TrimStartAndEnd();
    if (TrimmedQuery.IsEmpty())
    {
        return MatchingArtists;
    }

    const auto MatchesQuery = [&TrimmedQuery](UArtistAsset* Artist)
    {
        if (!Artist)
        {
            return false;
        }

        const FString& ArtistDisplayName = Artist->GetName();
        return ArtistDisplayName.Contains(TrimmedQuery, ESearchCase::IgnoreCase);
    };

    for (const TPair<FName, UArtistAsset*>& Pair : ArtistAssets)
    {
        if (UArtistAsset* Artist = Pair.Value)
        {
            if (MatchesQuery(Artist))
            {
                MatchingArtists.Add(Artist);
            }
        }
    }

    for (UArtistAsset* Artist : FiftiesRockArtists)
    {
        if (MatchesQuery(Artist) && !MatchingArtists.Contains(Artist))
        {
            MatchingArtists.Add(Artist);
        }
    }

    return MatchingArtists;
}

TArray<FString> UContentCatalogSubsystem::GetGenreTrends() const
{
    return {};
}

bool UContentCatalogSubsystem::TryGetFiftiesRockArtistByName(FName ArtistName, UArtistAsset*& OutArtist) const
{
    OutArtist = nullptr;

    if (const int32* ArtistIndex = FiftiesRockArtistIndexByName.Find(ArtistName))
    {
        if (FiftiesRockArtists.IsValidIndex(*ArtistIndex))
        {
            if (UArtistAsset* Artist = FiftiesRockArtists[*ArtistIndex])
            {
                OutArtist = Artist;
                return true;
            }
        }
    }

    return false;
}

