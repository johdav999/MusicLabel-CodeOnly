#include "ContentCatalogSubsystem.h"
#include "LabelManager/Public/LabelDataAssets.h"

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

