#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MusicLabelTypes.h"
#include "EconomySubsystem.generated.h"

/** Handles financial calculations and tracking. */
UCLASS()
class MUSICLABEL_API UEconomySubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Apply a financial transaction. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    void ApplyTransaction(const FTransaction& Transaction);

    /** Calculate cash flow for the current week. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    float CalculateWeeklyCashflow() const;

    /** Report profit and loss figures. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    void ReportPAndL() const;

private:
    /** Current cash balance. */
    float CashBalance = 0.0f;

    /** Revenue transactions. */
    TArray<FTransaction> RevenueStreams;

    /** Expense transactions. */
    TArray<FTransaction> Expenses;
};

