#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanel.h"
#include "Components/Border.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Widget_NewArtistAudition.generated.h"

class UTextBlock;
class UProgressBar;
class USlider;
class UButton;

UCLASS()
class LABELMANAGER_API UWidget_NewArtistAudition : public UUserWidget
{
    GENERATED_BODY()
public:
    //virtual TSharedRef<SWidget> RebuildWidget() override;

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UCanvasPanel* CanvasRoot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UTextBlock* TitleText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UImage* ArtistImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UTextBlock* ArtistNameText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UTextBlock* GenreText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UProgressBar* MusicalityBar;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UProgressBar* CharismaBar;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UProgressBar* CreativityBar;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    USlider* BidSlider;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    USlider* YearsSlider;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UTextBlock* ROIText;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UButton* SignButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Widgets")
    UButton* PassButton;

private:
    UFUNCTION()
    void OnSignClicked();

    UFUNCTION()
    void OnPassClicked();
};

