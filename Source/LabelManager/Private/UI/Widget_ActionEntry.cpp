#include "UI/Widget_ActionEntry.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "TimerManager.h"

void UWidget_ActionEntry::NativeOnListItemObjectSet(UObject* ListItem)
{
    USuggestedActionObject* Obj = Cast<USuggestedActionObject>(ListItem);
    if (Obj && ActionLabelText)
    {
        ActionLabelText->SetText(Obj->Action.Label);
        ActionLabelText->SetToolTipText(Obj->Action.Label);
    }
    PlayFadeIn();
}

void UWidget_ActionEntry::PlayFadeIn()
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
