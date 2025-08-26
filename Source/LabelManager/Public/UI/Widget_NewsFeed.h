#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardViewModel.h"
#include "Widget_NewsFeed.generated.h"

class UListView;

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

protected:
    UPROPERTY(meta=(BindWidget))
    UListView* NewsList;

    void PlayFadeIn();
};
