#include "UI/WidgetLibrary.h"
#include "UI/Widget_DashboardLayout.h"
#include "UI/DashboardViewModel.h"
#include "Blueprint/UserWidget.h"
#include "LabelManagerGameInstance.h"
#include "Engine/World.h"

UWidget_DashboardLayout* UWidgetLibrary::CreateDashboard(UWorld* World, APlayerController* PC)
{
    if (!World || !PC)
    {
        return nullptr;
    }

    if (ULabelManagerGameInstance* GameInstance = World->GetGameInstance<ULabelManagerGameInstance>())
    {
        if (UWidget_DashboardLayout* Layout = GameInstance->EnsureLayoutForPlayer(PC))
        {
            UDashboardViewModel* ViewModel = NewObject<UDashboardViewModel>(World);
            if (ViewModel)
            {
                ViewModel->RefreshAll();
                Layout->SetViewModel(ViewModel);
            }
            return Layout;
        }
    }

    UDashboardViewModel* ViewModel = NewObject<UDashboardViewModel>(World);
    if (!ViewModel)
    {
        return nullptr;
    }

    ViewModel->RefreshAll();

    UWidget_DashboardLayout* Layout = CreateWidget<UWidget_DashboardLayout>(PC, UWidget_DashboardLayout::StaticClass());
    if (Layout)
    {
        Layout->SetViewModel(ViewModel);
        Layout->AddToViewport();
    }
    return Layout;
}
