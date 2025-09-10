#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Layout.generated.h"

class UCanvasPanel;
class UWidget_NewsFeed;
struct FNewsItem;

UCLASS()
class LABELMANAGER_API ULayout : public UUserWidget
{
    GENERATED_BODY()

protected:

    UPROPERTY()
    UCanvasPanel* RootCanvas;

    UPROPERTY()
    UWidget_NewsFeed* NewsFeedWidget;

public:
    UFUNCTION(BlueprintCallable)
    void AddNewsItemToTop(const FNewsItem& Item);

    UFUNCTION(BlueprintCallable)
    void RemoveLastNewsItem();
};

