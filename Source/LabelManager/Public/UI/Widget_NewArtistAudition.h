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
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ArtistNameText;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* GenreText;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* MusicalityBar;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* CharismaBar;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* CreativityBar;

    UPROPERTY(meta = (BindWidget))
    USlider* BidSlider;

    UPROPERTY(meta = (BindWidget))
    USlider* YearsSlider;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ROIText;

    UPROPERTY(meta = (BindWidget))
    UButton* SignButton;

    UPROPERTY(meta = (BindWidget))
    UButton* PassButton;
};

