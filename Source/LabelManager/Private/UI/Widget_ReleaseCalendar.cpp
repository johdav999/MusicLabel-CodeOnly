#include "UI/Widget_ReleaseCalendar.h"
#include "UI/Widget_ReleaseItemEntry.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"
#include "Components/ListView.h"
#include "Blueprint/WidgetTree.h"
#include "TimerManager.h"

void UWidget_ReleaseCalendar::NativeConstruct()
{
    Super::NativeConstruct();
    if (UpcomingList && !UpcomingList->GetEntryWidgetClass())
    {
        UpcomingList->SetEntryWidgetClass(UWidget_ReleaseItemEntry::StaticClass());
    }
    PlayFadeIn();
}

void UWidget_ReleaseCalendar::SetMonth(int32 Year, int32 Month)
{
    if (MonthLabel)
    {
        FDateTime Date(Year, Month, 1);
        MonthLabel->SetText(FText::FromString(Date.ToString(TEXT("%B %Y"))));
    }
    if (CalendarGrid)
    {
        CalendarGrid->ClearChildren();
        int32 Days = FDateTime::DaysInMonth(Year, Month);
        for (int32 Day = 1; Day <= Days; ++Day)
        {
            UTextBlock* DayText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
            DayText->SetText(FText::AsNumber(Day));
            CalendarGrid->AddChildToUniformGrid(DayText, (Day - 1) / 7, (Day - 1) % 7);
        }
    }
}

void UWidget_ReleaseCalendar::SetReleases(const TArray<FReleaseItem>& InReleases)
{
    if (!UpcomingList) return;
    TArray<UObject*> Items;
    for (const FReleaseItem& Item : InReleases)
    {
        UReleaseItemObject* Obj = NewObject<UReleaseItemObject>(this);
        Obj->Item = Item;
        Items.Add(Obj);
    }
    UpcomingList->ClearListItems();
    UpcomingList->SetListItems(Items);
}

void UWidget_ReleaseCalendar::PlayFadeIn()
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
