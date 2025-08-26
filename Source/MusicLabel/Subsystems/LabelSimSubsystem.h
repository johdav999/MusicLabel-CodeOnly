#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LabelSimSubsystem.generated.h"

class UArtistAsset;
struct FRelease;

/** Subsystem managing label simulation timeline and events. */
UCLASS()
class MUSICLABEL_API ULabelSimSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Advance simulation by one day. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void TickDay();

    /** Update music charts for the current day. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void UpdateCharts();

    /** Process daily events. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void ProcessEvents();

    /** Apply modifiers based on the current decade. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void ApplyDecadeModifiers();

    /** Update marketing exposure values for active releases. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void UpdateMarketingExposures();

    /** Calculate consumer demand across demographics and regions. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void CalculateDemand();

    /** Convert demand into sales and streaming numbers. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void ConvertDemandToSales();

    /** Update fame, morale, and fatigue for all artists. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void UpdateArtistStates();

    /** Apply daily revenue, costs, and royalty transactions. */
    UFUNCTION(BlueprintCallable, Category="LabelSim")
    void ApplyFinanceTransactions();

private:
    /** Current date of the simulation. */
    FDateTime CurrentDate;

    /** Releases active on the charts. */
    TArray<FRelease> ActiveReleases;

    /** Artists currently signed to the label. */
    TArray<UArtistAsset*> SignedArtists;
};

