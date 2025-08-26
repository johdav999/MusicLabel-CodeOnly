#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MusicLabelTypes.h"
#include "ReleaseSubsystem.generated.h"

class UArtistAsset;

/** Handles planning and execution of music releases. */
UCLASS()
class MUSICLABEL_API UReleaseSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Select an artist for the upcoming release. */
    UFUNCTION(BlueprintCallable, Category="Release")
    void SelectArtist(UArtistAsset* Artist);

    /** Choose songs to include in the release. */
    UFUNCTION(BlueprintCallable, Category="Release")
    void ChooseSongs(const TArray<FSong>& Songs);

    /** Book studio time for recording. */
    UFUNCTION(BlueprintCallable, Category="Release")
    void BookStudio();

    /** Record the selected songs. */
    UFUNCTION(BlueprintCallable, Category="Release")
    void RecordSongs();

    /** Publish the release with distribution and marketing plans. */
    UFUNCTION(BlueprintCallable, Category="Release")
    void ReleaseMusic();
};

