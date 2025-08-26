#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardViewModel.h"
#include "Widget_ReleaseCalendar.generated.h"

class UTextBlock;
class UButton;
class UUniformGridPanel;
class UListView;

UCLASS()
class UReleaseItemObject : public UObject
{
    GENERATED_BODY()
public:
    FReleaseItem Item;
};

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_ReleaseCalendar : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetMonth(int32 Year, int32 Month);

    UFUNCTION(BlueprintCallable)
    void SetReleases(const TArray<FReleaseItem>& InReleases);

protected:
    UPROPERTY(meta=(BindWidget))
    UTextBlock* MonthLabel;

    UPROPERTY(meta=(BindWidget))
    UButton* PrevMonthBtn;

    UPROPERTY(meta=(BindWidget))
    UButton* NextMonthBtn;

    UPROPERTY(meta=(BindWidget))
    UUniformGridPanel* CalendarGrid;

    UPROPERTY(meta=(BindWidget))
    UListView* UpcomingList;

    void PlayFadeIn();
};
