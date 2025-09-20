#include "UI/Layout.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/Widget.h"
#include "UI/Widget_NewsFeed.h"
#include "UI/Widget_SignedArtists.h"
#include "Input/Events.h"
#include "InputCoreTypes.h"


ULayout::ULayout()
{
    FInputModeGameAndUI InputMode;
    InputMode.SetWidgetToFocus(TakeWidget());
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

    GetWorld()->GetFirstPlayerController()->SetInputMode(InputMode);
    GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}
void ULayout::AddNewsItemToTop(const FNewsItem& Item)
{
    if (NewsFeedWidget)
    {
        NewsFeedWidget->AddNewsItemToTop(Item);
    }
}

void ULayout::RemoveLastNewsItem()
{
    if (NewsFeedWidget)
    {
        NewsFeedWidget->RemoveLastNewsItem();
    }
}

void ULayout::ShowSignedArtistsWidget()
{
    if (SignedArtistsWidget)
    {
        SignedArtistsWidget->SetVisibility(ESlateVisibility::Visible);
    }
}

FReply ULayout::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    const FReply SuperReply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

    if (InMouseEvent.GetEffectingButton() != EKeys::RightMouseButton)
    {
        return SuperReply;
    }

    if (RootCanvas)
    {
        const int32 ChildCount = RootCanvas->GetChildrenCount();
        for (int32 ChildIndex = 0; ChildIndex < ChildCount; ++ChildIndex)
        {
            if (UWidget* ChildWidget = RootCanvas->GetChildAt(ChildIndex))
            {
                if (ChildWidget != NewsFeedWidget)
                {
                    ChildWidget->SetVisibility(ESlateVisibility::Hidden);
                }
            }
        }
    }

    return FReply::Handled();
}

