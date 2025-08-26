#include "UI/Widget_NewsFeed.h"
#include "Components/ListView.h"
#include "TimerManager.h"
#include "UI/Widget_NewsItemEntry.h"

void UWidget_NewsFeed::NativeConstruct() {
  Super::NativeConstruct();
  if (NewsList && !NewsList->GetEntryWidgetClass()) {
    NewsList->SetEntryWidgetClass(UWidget_NewsItemEntry::StaticClass());
  }
  PlayFadeIn();
}

void UWidget_NewsFeed::SetNews(const TArray<FNewsItem> &InNews) {
  if (!NewsList)
    return;
  TArray<UObject *> Items;
  for (const FNewsItem &Item : InNews) {
    UNewsItemObject *Obj = NewObject<UNewsItemObject>(this);
    Obj->Item = Item;
    Items.Add(Obj);
  }
  NewsList->ClearListItems();
  NewsList->SetListItems(Items);
}

void UWidget_NewsFeed::PlayFadeIn() {
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
