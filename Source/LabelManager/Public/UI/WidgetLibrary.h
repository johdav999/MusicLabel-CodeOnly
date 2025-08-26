#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "WidgetLibrary.generated.h"

class UWidget_DashboardLayout;
class UDashboardViewModel;
class APlayerController;

UCLASS()
class LABELMANAGER_API UWidgetLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="LabelUI", meta=(WorldContext="World"))
    static UWidget_DashboardLayout* CreateDashboard(UWorld* World, APlayerController* PC);
};
