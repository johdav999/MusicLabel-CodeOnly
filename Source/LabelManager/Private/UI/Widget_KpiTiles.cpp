#include "UI/Widget_KpiTiles.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"

void UWidget_KpiTiles::NativeConstruct()
{
    Super::NativeConstruct();

    if (CashValueText) CashValueText->SetToolTipText(FText::FromString("Available cash"));
    if (WeeklyStreamsText) WeeklyStreamsText->SetToolTipText(FText::FromString("Streams this week"));
    if (ChartingTitlesText) ChartingTitlesText->SetToolTipText(FText::FromString("Titles on charts"));
    if (ActiveCampaignsText) ActiveCampaignsText->SetToolTipText(FText::FromString("Active campaigns"));

    PlayFadeIn();
}

void UWidget_KpiTiles::SetMetrics(const FKpiMetrics& InMetrics)
{
    if (CashValueText)
    {
        CashValueText->SetText(FText::AsNumber(InMetrics.Cash));
    }
    if (WeeklyStreamsText)
    {
        WeeklyStreamsText->SetText(FText::AsNumber(InMetrics.WeeklyStreams));
    }
    if (ChartingTitlesText)
    {
        ChartingTitlesText->SetText(FText::AsNumber(InMetrics.ChartingTitles));
    }
    if (ActiveCampaignsText)
    {
        ActiveCampaignsText->SetText(FText::AsNumber(InMetrics.ActiveCampaigns));
    }
}

void UWidget_KpiTiles::PlayFadeIn()
{
    SetRenderOpacity(0.f);
    float Opacity = 0.f;
    GetWorld()->GetTimerManager().SetTimer(FadeTimer, [this, Opacity]() mutable
    {
        SetRenderOpacity(Opacity);
        Opacity += 0.1f;
        if (Opacity >= 1.f)
        {
            SetRenderOpacity(1.f);
            GetWorld()->GetTimerManager().ClearTimer(FadeTimer);
        }
    }, 0.05f, true);
}
