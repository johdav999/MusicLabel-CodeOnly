#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Input/Reply.h"
#include "Input/Events.h"
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



public:
    ULayout();
    UFUNCTION(BlueprintCallable)
    void AddNewsItemToTop(const FNewsItem& Item);

    UFUNCTION(BlueprintCallable)
    void RemoveLastNewsItem();

    UFUNCTION(BlueprintCallable)
    void ShowSignedArtistsWidget();

    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite,meta = (BindWidget))
    FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
    
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,meta = (BindWidget))
    UWidget_SignedArtists* SignedArtistsWidget;
};

