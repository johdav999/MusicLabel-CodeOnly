#include "UI/Layout.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "UI/Widget_NewsFeed.h"

TSharedRef<SWidget> ULayout::RebuildWidget()
{
    RootCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
    WidgetTree->RootWidget = RootCanvas;

    NewsFeedWidget = WidgetTree->ConstructWidget<UWidget_NewsFeed>(UWidget_NewsFeed::StaticClass(), TEXT("NewsFeed"));
    if (NewsFeedWidget)
    {
        RootCanvas->AddChild(NewsFeedWidget);
    }

    return RootCanvas->TakeWidget();
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

