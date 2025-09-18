#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Layout.generated.h"

class UCanvasPanel;
class UWidget_NewsFeed;
class UWidget_SignedArtists;
struct FNewsItem;

UCLASS()
class LABELMANAGER_API ULayout : public UUserWidget
{
    GENERATED_BODY()

protected:

    UPROPERTY(meta = (BindWidget))
    UCanvasPanel* RootCanvas;

    UPROPERTY(meta = (BindWidget))
    UWidget_NewsFeed* NewsFeedWidget;

    UPROPERTY(meta = (BindWidget))
    UWidget_SignedArtists* SignedArtistsWidget;

public:
    UFUNCTION(BlueprintCallable)
    void AddNewsItemToTop(const FNewsItem& Item);

    UFUNCTION(BlueprintCallable)
    void RemoveLastNewsItem();

    UFUNCTION(BlueprintCallable)
    void ShowSignedArtistsWidget();
};

