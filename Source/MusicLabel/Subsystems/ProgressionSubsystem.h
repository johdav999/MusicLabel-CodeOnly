#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ProgressionSubsystem.generated.h"

class UDecadeAsset;

/** Tracks player progression through decades and technology. */
UCLASS()
class MUSICLABEL_API UProgressionSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Advance to the next decade. */
    UFUNCTION(BlueprintCallable, Category="Progression")
    void AdvanceDecade();

    /** Unlock a new technology. */
    UFUNCTION(BlueprintCallable, Category="Progression")
    void UnlockTech(FName TechId);

    /** Apply era-specific shifts to the simulation. */
    UFUNCTION(BlueprintCallable, Category="Progression")
    void ApplyEraShifts();

private:
    /** Current active decade. */
    UDecadeAsset* CurrentDecade = nullptr;

    /** List of unlocked technology IDs. */
    TArray<FName> UnlockedTech;
};

