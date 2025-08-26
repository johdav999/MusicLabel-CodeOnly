#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TourSubsystem.generated.h"

struct FTour;
class UVenueAsset;

/** Handles tour planning and simulation. */
UCLASS()
class MUSICLABEL_API UTourSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Plan a new tour. */
    UFUNCTION(BlueprintCallable, Category="Tour")
    void PlanTour(const FTour& NewTour);

    /** Simulate a concert for the active tour. */
    UFUNCTION(BlueprintCallable, Category="Tour")
    void SimulateConcert();

    /** Calculate outcomes for the ongoing tour. */
    UFUNCTION(BlueprintCallable, Category="Tour")
    void CalculateTourOutcome();

private:
    /** Tours currently in progress. */
    TArray<FTour> ActiveTours;

    /** Database of potential venues. */
    TArray<UVenueAsset*> VenueDatabase;
};

