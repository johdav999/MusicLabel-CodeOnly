#include "UI/Widget_NewArtistAudition.h"
#include "Blueprint/WidgetTree.h"

#include "Components/GridPanel.h"
#include "Components/ProgressBar.h"
#include "Components/Slider.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Button.h"

TSharedRef<SWidget> UWidget_NewArtistAudition::RebuildWidget()
{
    WidgetTree = NewObject<UWidgetTree>(this, TEXT("WidgetTree"));

	CanvasRoot = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("CanvasRoot"));    
    WidgetTree->RootWidget = CanvasRoot;

    UBorder* OuterBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("OuterBorder"));
    OuterBorder->SetPadding(FMargin(16.f));
    OuterBorder->SetBrushColor(FLinearColor(0.05f, 0.05f, 0.05f, 1.f));
    UCanvasPanelSlot* BorderSlot = CanvasRoot->AddChildToCanvas(OuterBorder);
    BorderSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
    BorderSlot->SetOffsets(FMargin(0.f));

    UOverlay* Overlay = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay"));
    OuterBorder->SetContent(Overlay);

    UImage* Stripe = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Stripe"));
    Stripe->SetColorAndOpacity(FLinearColor(1.f, 0.8f, 0.f, 1.f));
    FSlateBrush StripeBrush;
    StripeBrush.DrawAs = ESlateBrushDrawType::Image;
    StripeBrush.TintColor = FSlateColor(FLinearColor(1.f, 0.8f, 0.f, 1.f));
    StripeBrush.ImageSize = FVector2D(6.f, 1.f);
    Stripe->SetBrush(StripeBrush);
    UOverlaySlot* StripeSlot = Overlay->AddChildToOverlay(Stripe);
    StripeSlot->SetHorizontalAlignment(HAlign_Left);
    StripeSlot->SetVerticalAlignment(VAlign_Fill);

    UVerticalBox* VBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("RootVBox"));
    UOverlaySlot* VBoxSlot = Overlay->AddChildToOverlay(VBox);
    VBoxSlot->SetPadding(FMargin(12.f, 8.f, 12.f, 8.f));

    UHorizontalBox* HeaderBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HeaderBox"));
    VBox->AddChildToVerticalBox(HeaderBox);

    ArtistImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("ArtistImage"));
    ArtistImage->SetColorAndOpacity(FLinearColor(1.f, 0.8f, 0.f, 1.f));
    CanvasRoot ->AddChildToCanvas(ArtistImage);

    UVerticalBox* HeaderTexts = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("HeaderTexts"));
    UHorizontalBoxSlot* HeaderTextSlot = HeaderBox->AddChildToHorizontalBox(HeaderTexts);
    HeaderTextSlot->SetPadding(FMargin(8.f, 0.f));

    TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TitleText"));
    TitleText->SetText(FText::FromString(TEXT("New Artist Audition")));
    TitleText->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.8f, 0.f, 1.f)));
    HeaderTexts->AddChildToVerticalBox(TitleText);

    UHorizontalBox* NameGenre = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("NameGenre"));
    HeaderTexts->AddChildToVerticalBox(NameGenre);

    ArtistNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ArtistNameText"));
    ArtistNameText->SetText(FText::FromString(TEXT("Artist")));
    NameGenre->AddChildToHorizontalBox(ArtistNameText);

    GenreText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("GenreText"));
    GenreText->SetText(FText::FromString(TEXT("Genre")));
    UHorizontalBoxSlot* GenreSlot = NameGenre->AddChildToHorizontalBox(GenreText);
    GenreSlot->SetPadding(FMargin(8.f, 0.f));
    GenreText->SetColorAndOpacity(FSlateColor(FLinearColor(0.f, 0.7f, 1.f, 1.f)));

    UTextBlock* Subtitle = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Subtitle"));
    Subtitle->SetText(FText::FromString(TEXT("Live audition recording.")));
    Subtitle->SetColorAndOpacity(FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f, 1.f)));
    VBox->AddChildToVerticalBox(Subtitle);

    UGridPanel* AttrGrid = WidgetTree->ConstructWidget<UGridPanel>(UGridPanel::StaticClass(), TEXT("AttrGrid"));
    UVerticalBoxSlot* AttrSlot = VBox->AddChildToVerticalBox(AttrGrid);
    AttrSlot->SetPadding(FMargin(0.f, 8.f));

    UTextBlock* MusicalityLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MusicalityLabel"));
    MusicalityLabel->SetText(FText::FromString(TEXT("Musicality")));
    MusicalityLabel->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.8f, 0.f, 1.f)));
    AttrGrid->AddChildToGrid(MusicalityLabel, 0, 0);
    MusicalityBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("MusicalityBar"));
    MusicalityBar->SetFillColorAndOpacity(FLinearColor(0.f, 0.8f, 1.f, 1.f));
    AttrGrid->AddChildToGrid(MusicalityBar, 0, 1);

    UTextBlock* CharismaLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CharismaLabel"));
    CharismaLabel->SetText(FText::FromString(TEXT("Charisma")));
    CharismaLabel->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.f, 0.5f, 1.f)));
    AttrGrid->AddChildToGrid(CharismaLabel, 1, 0);
    CharismaBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CharismaBar"));
    CharismaBar->SetFillColorAndOpacity(FLinearColor(1.f, 0.f, 0.5f, 1.f));
    AttrGrid->AddChildToGrid(CharismaBar, 1, 1);

    UTextBlock* CreativityLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CreativityLabel"));
    CreativityLabel->SetText(FText::FromString(TEXT("Creativity")));
    CreativityLabel->SetColorAndOpacity(FSlateColor(FLinearColor(0.f, 0.7f, 1.f, 1.f)));
    AttrGrid->AddChildToGrid(CreativityLabel, 2, 0);
    CreativityBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CreativityBar"));
    CreativityBar->SetFillColorAndOpacity(FLinearColor(0.f, 0.7f, 1.f, 1.f));
    AttrGrid->AddChildToGrid(CreativityBar, 2, 1);

    UHorizontalBox* ListeningBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ListeningBox"));
    VBox->AddChildToVerticalBox(ListeningBox);
    UImage* VinylImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("VinylImage"));
    ListeningBox->AddChildToHorizontalBox(VinylImage);
    UTextBlock* NowListening = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("NowListening"));
    NowListening->SetText(FText::FromString(TEXT("Now Listening: Venue Performance")));
    UHorizontalBoxSlot* NowSlot = ListeningBox->AddChildToHorizontalBox(NowListening);
    NowSlot->SetPadding(FMargin(8.f, 0.f));

    UVerticalBox* ContractBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("ContractBox"));
    VBox->AddChildToVerticalBox(ContractBox);

    UTextBlock* BidLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BidLabel"));
    BidLabel->SetText(FText::FromString(TEXT("Bid")));
    ContractBox->AddChildToVerticalBox(BidLabel);
    BidSlider = WidgetTree->ConstructWidget<USlider>(USlider::StaticClass(), TEXT("BidSlider"));
    ContractBox->AddChildToVerticalBox(BidSlider);

    UTextBlock* YearsLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("YearsLabel"));
    YearsLabel->SetText(FText::FromString(TEXT("Years")));
    ContractBox->AddChildToVerticalBox(YearsLabel);
    YearsSlider = WidgetTree->ConstructWidget<USlider>(USlider::StaticClass(), TEXT("YearsSlider"));
    ContractBox->AddChildToVerticalBox(YearsSlider);

    ROIText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ROIText"));
    ROIText->SetText(FText::FromString(TEXT("Projected ROI")));
    ContractBox->AddChildToVerticalBox(ROIText);

    UHorizontalBox* ButtonBox = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ButtonBox"));
    VBox->AddChildToVerticalBox(ButtonBox);

    SignButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("SignButton"));
    SignButton->SetBackgroundColor(FLinearColor(1.f, 0.8f, 0.f, 1.f));
    UTextBlock* SignLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SignLabel"));
    SignLabel->SetText(FText::FromString(TEXT("Sign Artist")));
    SignLabel->SetColorAndOpacity(FSlateColor(FLinearColor::Black));
    SignButton->AddChild(SignLabel);
    ButtonBox->AddChildToHorizontalBox(SignButton);

    PassButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PassButton"));
    PassButton->SetBackgroundColor(FLinearColor(0.15f, 0.15f, 0.15f, 1.f));
    UTextBlock* PassLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PassLabel"));
    PassLabel->SetText(FText::FromString(TEXT("Pass")));
    PassLabel->SetColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f, 1.f)));
    PassButton->AddChild(PassLabel);
    UHorizontalBoxSlot* PassSlot = ButtonBox->AddChildToHorizontalBox(PassButton);
    PassSlot->SetPadding(FMargin(8.f, 0.f));

    return WidgetTree->RootWidget->TakeWidget();
}

