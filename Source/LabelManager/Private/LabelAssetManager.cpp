#include "LabelAssetManager.h"
#include "CoreMinimal.h"

#include "Engine/Engine.h"

const FPrimaryAssetType ULabelAssetManager::SongAssetType(TEXT("Song"));
const FPrimaryAssetType ULabelAssetManager::ArtistAssetType(TEXT("Artist"));
const FPrimaryAssetType ULabelAssetManager::DecadeAssetType(TEXT("Decade"));
const FPrimaryAssetType ULabelAssetManager::GenreAssetType(TEXT("Genre"));
const FPrimaryAssetType ULabelAssetManager::RegionMarketAssetType(TEXT("RegionMarket"));
const FPrimaryAssetType ULabelAssetManager::VenueAssetType(TEXT("Venue"));

ULabelAssetManager& ULabelAssetManager::Get()
{
    ULabelAssetManager* Singleton = Cast<ULabelAssetManager>(GEngine->AssetManager);
    return *Singleton;
}

void ULabelAssetManager::StartInitialLoading()
{
    Super::StartInitialLoading();
}
