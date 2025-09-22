#include "UI/Widget_NewsItemEntry.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"

void UWidget_NewsItemEntry::NativeOnListItemObjectSet(UObject* ListItem)
{
    UNewsItemObject* Obj = Cast<UNewsItemObject>(ListItem);
    if (Obj && HeadlineText)
    {
        const FText Headline = FText::FromString(Obj->Item.Headline);
        HeadlineText->SetText(Headline);
        HeadlineText->SetToolTipText(Headline);
    }
    if (Obj && DateText)
    {
        DateText->SetText(FText::AsDate(Obj->Item.Date));
    }
    PlayFadeIn();
}

void UWidget_NewsItemEntry::PlayFadeIn()
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
