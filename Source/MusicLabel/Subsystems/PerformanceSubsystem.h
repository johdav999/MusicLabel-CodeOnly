#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PerformanceSubsystem.generated.h"

class UArtistAsset;
class USongAsset;
class ULevelStreaming;
class UObject;

/** Handles real-time performance simulation. */
UCLASS()
class MUSICLABEL_API UPerformanceSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Start a performance for the given artist and song. */
    UFUNCTION(BlueprintCallable, Category="Performance")
    void StartPerformance(UArtistAsset* Artist, USongAsset* Song);

    /** Stop the current performance. */
    UFUNCTION(BlueprintCallable, Category="Performance")
    void StopPerformance();

    /** Spawn audience crowd actors. */
    UFUNCTION(BlueprintCallable, Category="Performance")
    void SpawnCrowd();

private:
    /** Streaming level representing the show. */
    ULevelStreaming* CurrentShow = nullptr;

    /** Controller for managing crowd behavior. */
    UObject* CrowdController = nullptr;
};

