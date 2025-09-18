#include "UI/Layout.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "UI/Widget_NewsFeed.h"
#include "UI/Widget_SignedArtists.h"



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

