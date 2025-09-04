#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Layout.generated.h"

class UCanvasPanel;

UCLASS()
class LABELMANAGER_API ULayout : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual TSharedRef<SWidget> RebuildWidget() override;

    UPROPERTY()
    UCanvasPanel* RootCanvas;
};

