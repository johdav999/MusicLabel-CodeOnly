#include "LabelManagerGameInstance.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget_DashboardLayout.h"
#include "GameFramework/PlayerController.h"

ULabelManagerGameInstance::ULabelManagerGameInstance()
{
    LayoutGUIClass = UWidget_DashboardLayout::StaticClass();
}

void ULabelManagerGameInstance::Init()
{
    Super::Init();

    if (!LayoutGUI && LayoutGUIClass)
    {
        LayoutGUI = CreateWidget<UWidget_DashboardLayout>(this, LayoutGUIClass);
        if (LayoutGUI)
        {
            LayoutGUI->AddToViewport(0);
        }
    }
}

UWidget_DashboardLayout* ULabelManagerGameInstance::EnsureLayoutForPlayer(APlayerController* OwningPlayer)
{
    if (!LayoutGUI && LayoutGUIClass)
    {
        LayoutGUI = CreateWidget<UWidget_DashboardLayout>(this, LayoutGUIClass);
    }

    if (!LayoutGUI)
    {
        return nullptr;
    }

    if (OwningPlayer && LayoutGUI->GetOwningPlayer() != OwningPlayer)
    {
        LayoutGUI->SetOwningPlayer(OwningPlayer);
    }

    if (!LayoutGUI->IsInViewport())
    {
        LayoutGUI->AddToViewport(0);
    }

    return LayoutGUI;
}
