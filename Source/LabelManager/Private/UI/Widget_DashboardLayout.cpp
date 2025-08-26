#include "UI/Widget_DashboardLayout.h"
#include "UI/Widget_KpiTiles.h"
#include "UI/Widget_NewsFeed.h"
#include "UI/Widget_ReleaseCalendar.h"
#include "UI/Widget_MarketHeatmap.h"
#include "UI/Widget_SuggestedActions.h"
#include "Components/CanvasPanel.h"
#include "Components/GridPanel.h"
#include "Components/SizeBox.h"
#include "UI/DashboardViewModel.h"

void UWidget_DashboardLayout::NativeConstruct()
{
    Super::NativeConstruct();

    if (KpiSlot && !KpiWidget)
    {
        KpiWidget = CreateWidget<UWidget_KpiTiles>(GetWorld(), UWidget_KpiTiles::StaticClass());
        KpiSlot->SetContent(KpiWidget);
    }
    if (NewsSlot && !NewsWidget)
    {
        NewsWidget = CreateWidget<UWidget_NewsFeed>(GetWorld(), UWidget_NewsFeed::StaticClass());
        NewsSlot->SetContent(NewsWidget);
    }
    if (CalendarSlot && !CalendarWidget)
    {
        CalendarWidget = CreateWidget<UWidget_ReleaseCalendar>(GetWorld(), UWidget_ReleaseCalendar::StaticClass());
        CalendarSlot->SetContent(CalendarWidget);
    }
    if (HeatmapSlot && !HeatmapWidget)
    {
        HeatmapWidget = CreateWidget<UWidget_MarketHeatmap>(GetWorld(), UWidget_MarketHeatmap::StaticClass());
        HeatmapSlot->SetContent(HeatmapWidget);
    }
    if (ActionsSlot && !ActionsWidget)
    {
        ActionsWidget = CreateWidget<UWidget_SuggestedActions>(GetWorld(), UWidget_SuggestedActions::StaticClass());
        ActionsSlot->SetContent(ActionsWidget);
    }

    if (ViewModel)
    {
        KpiWidget->SetMetrics(ViewModel->GetKpiMetrics());
        NewsWidget->SetNews(ViewModel->GetNews());
        FDateTime Now = FDateTime::Now();
        CalendarWidget->SetMonth(Now.GetYear(), Now.GetMonth());
        CalendarWidget->SetReleases(ViewModel->GetReleases());
        HeatmapWidget->SetMarketStats(ViewModel->GetMarketStats());
        ActionsWidget->SetActions(ViewModel->GetActions());
    }
}

void UWidget_DashboardLayout::SetViewModel(UDashboardViewModel* InViewModel)
{
    ViewModel = InViewModel;
    if (!ViewModel) return;

    if (KpiWidget) KpiWidget->SetMetrics(ViewModel->GetKpiMetrics());
    if (NewsWidget) NewsWidget->SetNews(ViewModel->GetNews());
    if (CalendarWidget)
    {
        FDateTime Now = FDateTime::Now();
        CalendarWidget->SetMonth(Now.GetYear(), Now.GetMonth());
        CalendarWidget->SetReleases(ViewModel->GetReleases());
    }
    if (HeatmapWidget) HeatmapWidget->SetMarketStats(ViewModel->GetMarketStats());
    if (ActionsWidget) ActionsWidget->SetActions(ViewModel->GetActions());
}
