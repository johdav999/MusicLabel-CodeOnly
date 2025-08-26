#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Widget_MarketHeatmap.h"
#include "Widget_MarketRegionEntry.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class LABELMANAGER_API UWidget_MarketRegionEntry : public UUserWidget, public IUserObjectListEntry
{
    GENERATED_BODY()
public:
    virtual void NativeOnListItemObjectSet(UObject* ListItem) override;

protected:
    UPROPERTY(meta=(BindWidget))
    UTextBlock* RegionNameText;

    UPROPERTY(meta=(BindWidget))
    UProgressBar* IntensityBar;

    void PlayFadeIn();
};
