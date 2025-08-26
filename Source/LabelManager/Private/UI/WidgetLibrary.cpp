#include "UI/WidgetLibrary.h"
#include "UI/Widget_DashboardLayout.h"
#include "UI/DashboardViewModel.h"
#include "Blueprint/UserWidget.h"

UWidget_DashboardLayout* UWidgetLibrary::CreateDashboard(UWorld* World, APlayerController* PC)
{
    if (!World || !PC)
    {
        return nullptr;
    }

    UDashboardViewModel* ViewModel = NewObject<UDashboardViewModel>(World);
    ViewModel->RefreshAll();

    UWidget_DashboardLayout* Layout = CreateWidget<UWidget_DashboardLayout>(PC, UWidget_DashboardLayout::StaticClass());
    if (Layout)
    {
        Layout->SetViewModel(ViewModel);
        Layout->AddToViewport();
    }
    return Layout;
}
