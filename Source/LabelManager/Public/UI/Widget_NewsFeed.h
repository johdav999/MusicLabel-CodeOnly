#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardViewModel.h"
#include "TimerManager.h"
#include "Components/ListView.h"        // <-- IMPORTANT
#include "Widget_NewsFeed.generated.h"

class UListView;
struct FTimerHandle;

UCLASS()
class UNewsItemObject : public UObject
{
    GENERATED_BODY()
public:
    FNewsItem Item;
};

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_NewsFeed : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetNews(const TArray<FNewsItem>& InNews);

    UFUNCTION(BlueprintCallable)
    void AddNewsItemToTop(const FNewsItem& Item);

    UFUNCTION(BlueprintCallable)
    void RemoveLastNewsItem();

protected:
    UPROPERTY(meta=(BindWidget))
    UListView* NewsList;

    void PlayFadeIn();

    FTimerHandle FadeTimer;
};
