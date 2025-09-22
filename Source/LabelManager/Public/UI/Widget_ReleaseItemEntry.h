#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Widget_ReleaseCalendar.h"
#include "Widget_ReleaseItemEntry.generated.h"

class UTextBlock;
struct FTimerHandle;

UCLASS()
class LABELMANAGER_API UWidget_ReleaseItemEntry : public UUserWidget, public IUserObjectListEntry
{
    GENERATED_BODY()
public:
    virtual void NativeOnListItemObjectSet(UObject* ListItem) override;

protected:
    UPROPERTY(meta=(BindWidget))
    UTextBlock* TitleText;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* TypeText;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* DateText;

    void PlayFadeIn();

    FTimerHandle FadeTimer;
};
