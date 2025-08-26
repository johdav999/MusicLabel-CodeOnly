#include "UI/DashboardViewModel.h"

UDashboardViewModel::UDashboardViewModel()
{
    RefreshAll();
}

void UDashboardViewModel::RefreshAll()
{
    Kpi.Cash = 125000.0;
    Kpi.WeeklyStreams = 540000;
    Kpi.ChartingTitles = 12;
    Kpi.ActiveCampaigns = 3;

    News.Reset();
    News.Add({FText::FromString("Artist A tops charts"), FDateTime::UtcNow()});
    News.Add({FText::FromString("Label signs new talent"), FDateTime::UtcNow() - FTimespan::FromDays(1)});

    Releases.Reset();
    Releases.Add({FText::FromString("Album X"), FText::FromString("LP"), FDateTime::UtcNow() + FTimespan::FromDays(5)});
    Releases.Add({FText::FromString("Single Y"), FText::FromString("Single"), FDateTime::UtcNow() + FTimespan::FromDays(12)});

    MarketStats.Reset();
    MarketStats.Add({FName("NorthAmerica"), 0.8f});
    MarketStats.Add({FName("Europe"), 0.6f});
    MarketStats.Add({FName("Asia"), 0.4f});

    Actions.Reset();
    Actions.Add({FText::FromString("Review campaign budgets"), FName("BudgetReview")});
    Actions.Add({FText::FromString("Schedule artist interviews"), FName("ScheduleInterviews")});
}
