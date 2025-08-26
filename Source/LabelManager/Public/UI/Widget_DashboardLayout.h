#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_DashboardLayout.generated.h"

class UCanvasPanel;
class UGridPanel;
class USizeBox;
class UDashboardViewModel;
class UWidget_KpiTiles;
class UWidget_NewsFeed;
class UWidget_ReleaseCalendar;
class UWidget_MarketHeatmap;
class UWidget_SuggestedActions;

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_DashboardLayout : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetViewModel(UDashboardViewModel* InViewModel);

protected:
    UPROPERTY(meta=(BindWidget))
    UCanvasPanel* RootCanvas;

    UPROPERTY(meta=(BindWidget))
    UGridPanel* Grid;

    UPROPERTY(meta=(BindWidget))
    USizeBox* KpiSlot;

    UPROPERTY(meta=(BindWidget))
    USizeBox* NewsSlot;

    UPROPERTY(meta=(BindWidget))
    USizeBox* CalendarSlot;

    UPROPERTY(meta=(BindWidget))
    USizeBox* HeatmapSlot;

    UPROPERTY(meta=(BindWidget))
    USizeBox* ActionsSlot;

    UPROPERTY()
    UWidget_KpiTiles* KpiWidget;

    UPROPERTY()
    UWidget_NewsFeed* NewsWidget;

    UPROPERTY()
    UWidget_ReleaseCalendar* CalendarWidget;

    UPROPERTY()
    UWidget_MarketHeatmap* HeatmapWidget;

    UPROPERTY()
    UWidget_SuggestedActions* ActionsWidget;

    UPROPERTY()
    UDashboardViewModel* ViewModel;
};
