#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ContentCatalogSubsystem.generated.h"

class USongAsset;
class UArtistAsset;
class UGenreAsset;

/** Provides catalog access to songs, artists, and genres. */
UCLASS()
class MUSICLABEL_API UContentCatalogSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Retrieve songs matching a specific genre. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    TArray<USongAsset*> FindSongsByGenre(FName Genre) const;

    /** Get an artist asset by name. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    UArtistAsset* GetArtistByName(FName ArtistName) const;

    /** Gather trends across genres. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    TArray<FString> GetGenreTrends() const;

private:
    /** Map of song assets by identifier. */
    TMap<FName, USongAsset*> SongAssets;

    /** Map of artist assets by name. */
    TMap<FName, UArtistAsset*> ArtistAssets;

    /** Map of genre assets by name. */
    TMap<FName, UGenreAsset*> GenreAssets;
};

