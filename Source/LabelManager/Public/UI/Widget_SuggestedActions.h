#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardViewModel.h"
#include "Widget_SuggestedActions.generated.h"

class UListView;

UCLASS()
class USuggestedActionObject : public UObject
{
    GENERATED_BODY()
public:
    FSuggestedAction Action;
};

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_SuggestedActions : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetActions(const TArray<FSuggestedAction>& InActions);

protected:
    UPROPERTY(meta=(BindWidget))
    UListView* ActionsList;

    void PlayFadeIn();
};
