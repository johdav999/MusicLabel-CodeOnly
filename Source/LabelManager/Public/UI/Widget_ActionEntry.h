#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Widget_SuggestedActions.h"
#include "Widget_ActionEntry.generated.h"

class UTextBlock;
class UButton;
struct FTimerHandle;

UCLASS()
class LABELMANAGER_API UWidget_ActionEntry : public UUserWidget, public IUserObjectListEntry
{
    GENERATED_BODY()
public:
    virtual void NativeOnListItemObjectSet(UObject* ListItem) override;

protected:
    UPROPERTY(meta=(BindWidget))
    UTextBlock* ActionLabelText;

    UPROPERTY(meta=(BindWidget))
    UButton* GoButton;

    void PlayFadeIn();

    FTimerHandle FadeTimer;
};
