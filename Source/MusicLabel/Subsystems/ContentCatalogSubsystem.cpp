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
        const FString& ArtistName = FiftiesRockArtists[Index].GetName();
        if (!ArtistName.IsEmpty())
        {
            FiftiesRockArtistIndexByName.Add(FName(*ArtistName), Index);
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

TArray<FString> UContentCatalogSubsystem::GetGenreTrends() const
{
    return {};
}

bool UContentCatalogSubsystem::TryGetFiftiesRockArtistByName(FName ArtistName, FArtistAttributes& OutArtist) const
{
    if (const int32* ArtistIndex = FiftiesRockArtistIndexByName.Find(ArtistName))
    {
        if (FiftiesRockArtists.IsValidIndex(*ArtistIndex))
        {
            OutArtist = FiftiesRockArtists[*ArtistIndex];
            return true;
        }
    }

    return false;
}

