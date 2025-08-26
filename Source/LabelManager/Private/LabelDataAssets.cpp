#include "CoreMinimal.h"
#include "LabelDataAssets.h"
#include "LabelAssetManager.h"

FPrimaryAssetId USongAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(ULabelAssetManager::SongAssetType, GetFName());
}

FPrimaryAssetId UArtistAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(ULabelAssetManager::ArtistAssetType, GetFName());
}

FPrimaryAssetId UDecadeAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(ULabelAssetManager::DecadeAssetType, GetFName());
}

FPrimaryAssetId UGenreAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(ULabelAssetManager::GenreAssetType, GetFName());
}

FPrimaryAssetId URegionMarketAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(ULabelAssetManager::RegionMarketAssetType, GetFName());
}

FPrimaryAssetId UVenueAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(ULabelAssetManager::VenueAssetType, GetFName());
}

FPrimaryAssetId UEconomyConfigAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(FPrimaryAssetType(TEXT("EconomyConfig")), GetFName());
}
