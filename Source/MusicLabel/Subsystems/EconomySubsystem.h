#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EconomySubsystem.generated.h"

struct FTransaction;

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

    /** Track studio costs, marketing spend, and advances. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    void TrackCosts();

    /** Collect revenues from sales, streaming, tickets, merch, and licensing. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    void CollectRevenues();

    /** Generate monthly profit and loss reports. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    void GenerateMonthlyReport();

    /** Recoup advances before paying artist royalties. */
    UFUNCTION(BlueprintCallable, Category="Economy")
    void RecoupAdvances();

private:
    /** Current cash balance. */
    float CashBalance = 0.0f;

    /** Revenue transactions. */
    TArray<FTransaction> RevenueStreams;

    /** Expense transactions. */
    TArray<FTransaction> Expenses;
};

