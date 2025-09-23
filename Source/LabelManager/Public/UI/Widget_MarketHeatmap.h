#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardViewModel.h"
#include "Widget_MarketHeatmap.generated.h"

class UListView;
struct FTimerHandle;

UCLASS()
class UMarketRegionObject : public UObject
{
    GENERATED_BODY()
public:
    FMarketRegionStat Stat;
};

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_MarketHeatmap : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetMarketStats(const TArray<FMarketRegionStat>& InStats);

protected:
    UPROPERTY(meta=(BindWidget))
    UListView* HeatList;

    void PlayFadeIn();

    FTimerHandle FadeTimer;
};
