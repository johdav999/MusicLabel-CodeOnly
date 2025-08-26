#include "UI/Widget_MarketRegionEntry.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "TimerManager.h"

void UWidget_MarketRegionEntry::NativeOnListItemObjectSet(UObject* ListItem)
{
    UMarketRegionObject* Obj = Cast<UMarketRegionObject>(ListItem);
    if (Obj && RegionNameText)
    {
        RegionNameText->SetText(FText::FromName(Obj->Stat.Region));
        RegionNameText->SetToolTipText(FText::FromName(Obj->Stat.Region));
    }
    if (Obj && IntensityBar)
    {
        IntensityBar->SetPercent(Obj->Stat.Intensity01);
    }
    PlayFadeIn();
}

void UWidget_MarketRegionEntry::PlayFadeIn()
{
    SetRenderOpacity(0.f);
    float Opacity = 0.f;
    FTimerHandle Timer;
    GetWorld()->GetTimerManager().SetTimer(Timer, [this, Opacity]() mutable
    {
        SetRenderOpacity(Opacity);
        Opacity += 0.1f;
        if (Opacity >= 1.f)
        {
            SetRenderOpacity(1.f);
            GetWorld()->GetTimerManager().ClearTimer(Timer);
        }
    }, 0.05f, true);
}
