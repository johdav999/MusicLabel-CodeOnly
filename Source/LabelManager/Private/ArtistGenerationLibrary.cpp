#include "ArtistGenerationLibrary.h"

#include "Math/RandomStream.h"
#include "Misc/DateTime.h"
#include "UObject/Package.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/UObjectGlobals.h"

namespace
{
    /** Pool of given names to mix for generated artists. */
    const TArray<FString> GivenNames = {
        TEXT("Buddy"),
        TEXT("Eddie"),
        TEXT("Ruth"),
        TEXT("Connie"),
        TEXT("Little"),
        TEXT("Frankie"),
        TEXT("Marty"),
        TEXT("Peggy"),
        TEXT("Johnny"),
        TEXT("Laverne")
    };

    /** Pool of family names to mix for generated artists. */
    const TArray<FString> FamilyNames = {
        TEXT("Holly"),
        TEXT("Cochran"),
        TEXT("Brown"),
        TEXT("Francis"),
        TEXT("Richard"),
        TEXT("Avalon"),
        TEXT("Robbins"),
        TEXT("Lee"),
        TEXT("Burnette"),
        TEXT("Baker")
    };

    /** Soft reference path to the dedicated 50:ies rock genre asset. */
    const FSoftObjectPath FiftysRockGenrePath(TEXT("/Game/Data/Genres/50iesRock.50iesRock"));

    /** Pool of artist types for randomized generation. */
    const TArray<EArtistType> ArtistTypes = {
        EArtistType::Solo,
        EArtistType::Band
    };

    /** Pool of personality flags to randomly assign. */
    const TArray<EPersonalityFlag> PersonalityFlagPool = {
        EPersonalityFlag::Ego,
        EPersonalityFlag::Activism,
        EPersonalityFlag::RiskTaker
    };

    /** Returns a randomized float score within a reasonable gameplay-friendly range. */
    float GenerateAttributeScore(FRandomStream& RandomStream)
    {
        return RandomStream.FRandRange(40.f, 100.f);
    }

    /** Shuffles the provided array using the supplied random stream. */
    template<typename ArrayType>
    void ShuffleArray(TArray<ArrayType>& Array, FRandomStream& RandomStream)
    {
        for (int32 Index = Array.Num() - 1; Index > 0; --Index)
        {
            const int32 SwapIndex = RandomStream.RandRange(0, Index);
            if (SwapIndex != Index)
            {
                Array.Swap(Index, SwapIndex);
            }
        }
    }
    /** Selects a random artist type. */
    EArtistType GenerateArtistType(FRandomStream& RandomStream)
    {
        const int32 TypeIndex = RandomStream.RandRange(0, ArtistTypes.Num() - 1);
        return ArtistTypes[TypeIndex];
    }

    /** Generates a randomized set of personality flags. */
    TArray<EPersonalityFlag> GeneratePersonalityFlags(FRandomStream& RandomStream)
    {
        TArray<EPersonalityFlag> ShuffledFlags = PersonalityFlagPool;
        ShuffleArray(ShuffledFlags, RandomStream);

        const int32 FlagCount = RandomStream.RandRange(0, PersonalityFlagPool.Num());
        TArray<EPersonalityFlag> Result;
        Result.Reserve(FlagCount);

        for (int32 Index = 0; Index < FlagCount; ++Index)
        {
            Result.Add(ShuffledFlags[Index]);
        }

        return Result;
    }

    /** Creates randomized contract terms for an artist. */
    FContractTerms GenerateContractTerms(FRandomStream& RandomStream)
    {
        FContractTerms Terms;
        Terms.SetAdvance(RandomStream.RandRange(1000, 5000));
        Terms.SetRoyaltySplit(RandomStream.FRandRange(0.05f, 0.25f));
        Terms.SetRecordsNumber(RandomStream.RandRange(1, 5));
        return Terms;
    }
}

TArray<UArtistAsset*> UArtistGenerationLibrary::GenerateFiftiesRockArtists(int32 Count)
{
    TArray<UArtistAsset*> Result;
    if (Count <= 0)
    {
        return Result;
    }

    Result.Reserve(Count);

    FRandomStream RandomStream(FDateTime::UtcNow().GetTicks());

    TArray<FString> ShuffledGivenNames = GivenNames;
    TArray<FString> ShuffledFamilyNames = FamilyNames;
    ShuffleArray(ShuffledGivenNames, RandomStream);
    ShuffleArray(ShuffledFamilyNames, RandomStream);

    const TSoftObjectPtr<UGenreAsset> FiftysRockGenre(FiftysRockGenrePath);
    const TArray<TSoftObjectPtr<UGenreAsset>> ArtistGenres = { FiftysRockGenre };

    for (int32 Index = 0; Index < Count; ++Index)
    {
        const FString& GivenName = ShuffledGivenNames[Index % ShuffledGivenNames.Num()];
        const FString& FamilyName = ShuffledFamilyNames[Index % ShuffledFamilyNames.Num()];
        const FString FullName = FString::Printf(TEXT("%s %s"), *GivenName, *FamilyName);

        UArtistAsset* ArtistAsset = NewObject<UArtistAsset>(GetTransientPackage());
        if (!ArtistAsset)
        {
            continue;
        }

        ArtistAsset->SetFlags(RF_Transient);

        FArtistAttributes Attributes;
        Attributes.SetName(FullName);
        Attributes.SetTalent(GenerateAttributeScore(RandomStream));
        Attributes.SetCharisma(GenerateAttributeScore(RandomStream));
        Attributes.SetReliability(GenerateAttributeScore(RandomStream));
        Attributes.SetMarketAppeal(GenerateAttributeScore(RandomStream));
        Attributes.SetStamina(GenerateAttributeScore(RandomStream));
        Attributes.SetMusicality(GenerateAttributeScore(RandomStream));
        Attributes.SetCreativity(GenerateAttributeScore(RandomStream));
        Attributes.SetGenres(ArtistGenres);

        ArtistAsset->SetName(FullName);
        ArtistAsset->SetType(GenerateArtistType(RandomStream));
        ArtistAsset->SetAttributes(Attributes);
        ArtistAsset->SetGenreAffinity(ArtistGenres);
        ArtistAsset->SetPersonalityFlags(GeneratePersonalityFlags(RandomStream));
        ArtistAsset->SetContractTerms(GenerateContractTerms(RandomStream));

        Result.Add(ArtistAsset);
    }

    return Result;
}

