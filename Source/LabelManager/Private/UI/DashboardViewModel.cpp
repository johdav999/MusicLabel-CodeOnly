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
    FNewsItem FirstNews;
    FirstNews.Headline = TEXT("Artist A tops charts");
    FirstNews.Date = FDateTime::UtcNow();
    News.Add(FirstNews);

    FNewsItem SecondNews;
    SecondNews.Headline = TEXT("Label signs new talent");
    SecondNews.Date = FDateTime::UtcNow() - FTimespan::FromDays(1);
    News.Add(SecondNews);

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
