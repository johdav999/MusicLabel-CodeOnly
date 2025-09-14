#include "UI/Layout.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "UI/Widget_NewsFeed.h"



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

