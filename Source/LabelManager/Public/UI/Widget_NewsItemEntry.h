#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Widget_NewsFeed.h"
#include "Widget_NewsItemEntry.generated.h"

class UTextBlock;

UCLASS()
class LABELMANAGER_API UWidget_NewsItemEntry : public UUserWidget, public IUserObjectListEntry
{
    GENERATED_BODY()
public:
    virtual void NativeOnListItemObjectSet(UObject* ListItem) override;

protected:
    UPROPERTY(meta=(BindWidget))
    UTextBlock* HeadlineText;

    UPROPERTY(meta=(BindWidget))
    UTextBlock* DateText;

    void PlayFadeIn();
};
