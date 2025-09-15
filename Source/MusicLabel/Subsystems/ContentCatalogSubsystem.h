#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "LabelManager/Public/LabelDataAssets.h"
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
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    /** Retrieve songs matching a specific genre. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    TArray<USongAsset*> FindSongsByGenre(FName Genre) const;

    /** Get an artist asset by name. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    UArtistAsset* GetArtistByName(FName ArtistName) const;

    /** Gather trends across genres. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    TArray<FString> GetGenreTrends() const;

    /** Access the generated 50ies rock artists. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    TArray<FArtistAttributes> GetFiftiesRockArtists() const { return FiftiesRockArtists; }

    /** Find a generated 50ies rock artist by name. */
    UFUNCTION(BlueprintCallable, Category="ContentCatalog")
    bool TryGetFiftiesRockArtistByName(FName ArtistName, FArtistAttributes& OutArtist) const;

private:
    /** Map of song assets by identifier. */
    TMap<FName, USongAsset*> SongAssets;

    /** Map of artist assets by name. */
    TMap<FName, UArtistAsset*> ArtistAssets;

    /** Map of genre assets by name. */
    TMap<FName, UGenreAsset*> GenreAssets;

    /** Generated artist attributes for 50ies rock artists available at runtime. */
    TArray<FArtistAttributes> FiftiesRockArtists;

    /** Index lookup for generated 50ies rock artists by name. */
    TMap<FName, int32> FiftiesRockArtistIndexByName;
};

