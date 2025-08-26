#include "UI/Widget_MarketHeatmap.h"
#include "UI/Widget_MarketRegionEntry.h"
#include "Components/ListView.h"
#include "TimerManager.h"

void UWidget_MarketHeatmap::NativeConstruct()
{
    Super::NativeConstruct();
    if (HeatList && !HeatList->GetEntryWidgetClass())
    {
        HeatList->SetEntryWidgetClass(UWidget_MarketRegionEntry::StaticClass());
    }
    PlayFadeIn();
}

void UWidget_MarketHeatmap::SetMarketStats(const TArray<FMarketRegionStat>& InStats)
{
    if (!HeatList) return;
    TArray<UObject*> Items;
    for (const FMarketRegionStat& Stat : InStats)
    {
        UMarketRegionObject* Obj = NewObject<UMarketRegionObject>(this);
        Obj->Stat = Stat;
        Items.Add(Obj);
    }
    HeatList->ClearListItems();
    HeatList->SetListItems(Items);
}

void UWidget_MarketHeatmap::PlayFadeIn()
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
