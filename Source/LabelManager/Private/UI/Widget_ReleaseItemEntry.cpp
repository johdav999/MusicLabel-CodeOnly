#include "UI/Widget_ReleaseItemEntry.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"

void UWidget_ReleaseItemEntry::NativeOnListItemObjectSet(UObject* ListItem)
{
    UReleaseItemObject* Obj = Cast<UReleaseItemObject>(ListItem);
    if (Obj && TitleText)
    {
        TitleText->SetText(Obj->Item.Title);
    }
    if (Obj && TypeText)
    {
        TypeText->SetText(Obj->Item.Type);
    }
    if (Obj && DateText)
    {
        DateText->SetText(FText::AsDate(Obj->Item.Date));
    }
    PlayFadeIn();
}

void UWidget_ReleaseItemEntry::PlayFadeIn()
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
