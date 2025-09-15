#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
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
    virtual TSharedRef<SWidget> RebuildWidget() override;

protected:
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
};

