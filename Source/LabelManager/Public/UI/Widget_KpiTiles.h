#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardViewModel.h"
#include "Widget_KpiTiles.generated.h"

class UTextBlock;
struct FTimerHandle;

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_KpiTiles : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetMetrics(const FKpiMetrics& InMetrics);

protected:
    UPROPERTY(meta=(BindWidget))
    UTextBlock* CashValueText;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* WeeklyStreamsText;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* ChartingTitlesText;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* ActiveCampaignsText;

    void PlayFadeIn();

    FTimerHandle FadeTimer;
};
