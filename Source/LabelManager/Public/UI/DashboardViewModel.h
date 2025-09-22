#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LabelManager/public/LabelDataAssets.h"
#include "DashboardViewModel.generated.h"

USTRUCT(BlueprintType)
struct FKpiMetrics
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double Cash = 0.0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 WeeklyStreams = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ChartingTitles = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ActiveCampaigns = 0;
};

USTRUCT(BlueprintType)
struct FNewsItem : public FGameEvent
{
    GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FReleaseItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FDateTime Date;
};

USTRUCT(BlueprintType)
struct FMarketRegionStat
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Region;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Intensity01 = 0.f;
};

USTRUCT(BlueprintType)
struct FSuggestedAction
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Label;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ActionId;
};

UCLASS(BlueprintType)
class LABELMANAGER_API UDashboardViewModel : public UObject
{
    GENERATED_BODY()
public:
    UDashboardViewModel();

    const FKpiMetrics& GetKpiMetrics() const { return Kpi; }
    const TArray<FNewsItem>& GetNews() const { return News; }
    const TArray<FReleaseItem>& GetReleases() const { return Releases; }
    const TArray<FMarketRegionStat>& GetMarketStats() const { return MarketStats; }
    const TArray<FSuggestedAction>& GetActions() const { return Actions; }

    UFUNCTION(BlueprintCallable)
    void RefreshAll();

private:
    FKpiMetrics Kpi;
    TArray<FNewsItem> News;
    TArray<FReleaseItem> Releases;
    TArray<FMarketRegionStat> MarketStats;
    TArray<FSuggestedAction> Actions;
};
