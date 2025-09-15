#include "ArtistGenerationLibrary.h"

#include "Math/RandomStream.h"
#include "Misc/DateTime.h"
#include "UObject/SoftObjectPath.h"

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

    /** Returns a randomized float score within a reasonable gameplay-friendly range. */
    float GenerateAttributeScore(FRandomStream& RandomStream)
    {
        return RandomStream.FRandRange(40.f, 100.f);
    }
}

TArray<FArtistAttributes> UArtistGenerationLibrary::GenerateFiftiesRockArtists(int32 Count)
{
    TArray<FArtistAttributes> Result;
    if (Count <= 0)
    {
        return Result;
    }

    Result.Reserve(Count);

    FRandomStream RandomStream(FDateTime::UtcNow().GetTicks());

    TArray<FString> ShuffledGivenNames = GivenNames;
    TArray<FString> ShuffledFamilyNames = FamilyNames;
    RandomStream.Shuffle(ShuffledGivenNames);
    RandomStream.Shuffle(ShuffledFamilyNames);

    const TSoftObjectPtr<UGenreAsset> FiftysRockGenre(FiftysRockGenrePath);
    const TArray<TSoftObjectPtr<UGenreAsset>> ArtistGenres = { FiftysRockGenre };

    for (int32 Index = 0; Index < Count; ++Index)
    {
        FArtistAttributes Artist;
        const FString& GivenName = ShuffledGivenNames[Index % ShuffledGivenNames.Num()];
        const FString& FamilyName = ShuffledFamilyNames[Index % ShuffledFamilyNames.Num()];

        Artist.SetName(FString::Printf(TEXT("%s %s"), *GivenName, *FamilyName));
        Artist.SetTalent(GenerateAttributeScore(RandomStream));
        Artist.SetCharisma(GenerateAttributeScore(RandomStream));
        Artist.SetReliability(GenerateAttributeScore(RandomStream));
        Artist.SetMarketAppeal(GenerateAttributeScore(RandomStream));
        Artist.SetStamina(GenerateAttributeScore(RandomStream));
        Artist.SetMusicality(GenerateAttributeScore(RandomStream));
        Artist.SetCreativity(GenerateAttributeScore(RandomStream));
        Artist.SetGenres(ArtistGenres);

        Result.Add(Artist);
    }

    return Result;
}

