#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "WidgetLibrary.generated.h"

class ULayout;
class APlayerController;

UCLASS()
class LABELMANAGER_API UWidgetLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="LabelUI", meta=(WorldContext="World"))
    static ULayout* CreateDashboard(UWorld* World, APlayerController* PC);
};
