#include "UI/Layout.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"

TSharedRef<SWidget> ULayout::RebuildWidget()
{
    RootCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootCanvas"));
    WidgetTree->RootWidget = RootCanvas;
    return RootCanvas->TakeWidget();
}

