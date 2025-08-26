#pragma once

#include "Engine/AssetManager.h"
#include "LabelAssetManager.generated.h"

/**
 * Central asset manager for label assets.
 */
UCLASS()
class LABELMANAGER_API ULabelAssetManager : public UAssetManager
{
    GENERATED_BODY()
public:
    /** Returns the global asset manager instance */
    static ULabelAssetManager& Get();

    static const FPrimaryAssetType SongAssetType;
    static const FPrimaryAssetType ArtistAssetType;
    static const FPrimaryAssetType DecadeAssetType;
    static const FPrimaryAssetType GenreAssetType;
    static const FPrimaryAssetType RegionMarketAssetType;
    static const FPrimaryAssetType VenueAssetType;

protected:
    // UAssetManager interface
    virtual void StartInitialLoading() override;
};
