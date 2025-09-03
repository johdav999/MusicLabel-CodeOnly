#include "UI/Widget_MarketHeatmap.h"
#include "Components/ListView.h"
#include "TimerManager.h"
#include "UI/Widget_MarketRegionEntry.h"

void UWidget_MarketHeatmap::NativeConstruct() {
  Super::NativeConstruct();
  //if (HeatList && !HeatList->GetEntryWidgetClass()) {
  //  HeatList->SetEntryWidgetClass(UWidget_MarketRegionEntry::StaticClass());
  //}
  PlayFadeIn();
}

void UWidget_MarketHeatmap::SetMarketStats(
    const TArray<FMarketRegionStat> &InStats) {
  if (!HeatList)
    return;
  TArray<UObject *> Items;
  for (const FMarketRegionStat &Stat : InStats) {
    UMarketRegionObject *Obj = NewObject<UMarketRegionObject>(this);
    Obj->Stat = Stat;
    Items.Add(Obj);
  }
  HeatList->ClearListItems();
  HeatList->SetListItems(Items);
}

void UWidget_MarketHeatmap::PlayFadeIn() {
  SetRenderOpacity(0.f);
  float Opacity = 0.f;
  GetWorld()->GetTimerManager().SetTimer(
      FadeTimer,
      [this, Opacity]() mutable {
        SetRenderOpacity(Opacity);
        Opacity += 0.1f;
        if (Opacity >= 1.f) {
          SetRenderOpacity(1.f);
          GetWorld()->GetTimerManager().ClearTimer(FadeTimer);
        }
      },
      0.05f, true);
}
