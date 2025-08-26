#include "UI/Widget_SuggestedActions.h"
#include "UI/Widget_ActionEntry.h"
#include "Components/ListView.h"
#include "TimerManager.h"

void UWidget_SuggestedActions::NativeConstruct()
{
    Super::NativeConstruct();
    if (ActionsList && !ActionsList->EntryWidgetClass)
    {
        ActionsList->EntryWidgetClass = UWidget_ActionEntry::StaticClass();
    }
    PlayFadeIn();
}

void UWidget_SuggestedActions::SetActions(const TArray<FSuggestedAction>& InActions)
{
    if (!ActionsList) return;
    TArray<UObject*> Items;
    for (const FSuggestedAction& Action : InActions)
    {
        USuggestedActionObject* Obj = NewObject<USuggestedActionObject>(this);
        Obj->Action = Action;
        Items.Add(Obj);
    }
    ActionsList->ClearListItems();
    ActionsList->SetListItems(Items);
}

void UWidget_SuggestedActions::PlayFadeIn()
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
