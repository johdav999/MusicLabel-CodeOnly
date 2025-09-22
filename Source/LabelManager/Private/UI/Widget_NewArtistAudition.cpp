#include "UI/Widget_NewArtistAudition.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "Components/Slider.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Button.h"


void UWidget_NewArtistAudition::NativeConstruct()
{
    Super::NativeConstruct();

    if (SignButton)
    {
        SignButton->OnClicked.AddDynamic(this, &UWidget_NewArtistAudition::OnSignClicked);
    }

    if (PassButton)
    {
        PassButton->OnClicked.AddDynamic(this, &UWidget_NewArtistAudition::OnPassClicked);
    }
}

void UWidget_NewArtistAudition::OnSignClicked()
{
    UE_LOG(LogTemp, Log, TEXT("Artist Signed!"));
}

void UWidget_NewArtistAudition::OnPassClicked()
{
    UE_LOG(LogTemp, Log, TEXT("Artist Passed."));
}



//
//TSharedRef<SWidget> UWidget_NewArtistAudition::RebuildWidget()
//{
//    WidgetTree = NewObject<UWidgetTree>(this, TEXT("WidgetTree"));
//
//	CanvasRoot = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("CanvasRoot"));    
//    WidgetTree->RootWidget = CanvasRoot;
//
//    // Background
//    UBorder* OuterBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("OuterBorder"));
//    OuterBorder->SetBrushColor(FLinearColor(0.05f, 0.05f, 0.05f, 1.f));
//    UCanvasPanelSlot* BorderSlot = CanvasRoot->AddChildToCanvas(OuterBorder);
//    BorderSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
//    BorderSlot->SetOffsets(FMargin(0.f));
//    BorderSlot->SetZOrder(0);
//
//    // Left stripe
//    UImage* Stripe = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Stripe"));
//    FSlateBrush StripeBrush;
//    StripeBrush.DrawAs = ESlateBrushDrawType::Image;
//    StripeBrush.TintColor = FSlateColor(FLinearColor(1.f, 0.8f, 0.f, 1.f));
//    StripeBrush.ImageSize = FVector2D(6.f, 1.f);
//    Stripe->SetBrush(StripeBrush);
//    UCanvasPanelSlot* StripeSlot = CanvasRoot->AddChildToCanvas(Stripe);
//    StripeSlot->SetAnchors(FAnchors(0.f, 0.f, 0.f, 1.f));
//    StripeSlot->SetOffsets(FMargin(0.f, 0.f, 6.f, 0.f));
//    StripeSlot->SetZOrder(1);
//
//    // Header
//     ArtistImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("ArtistImage"));
//    ArtistImage->SetColorAndOpacity(FLinearColor(1.f, 0.8f, 0.f, 1.f));
//    UCanvasPanelSlot* ArtistSlot = CanvasRoot->AddChildToCanvas(ArtistImage);
//    ArtistSlot->SetPosition(FVector2D(16.f, 16.f));
//    ArtistSlot->SetAutoSize(true);
//    ArtistSlot->SetZOrder(2);
//
//    TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TitleText"));
//    TitleText->SetText(FText::FromString(TEXT("New Artist Audition")));
//    TitleText->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.8f, 0.f, 1.f)));
//    UCanvasPanelSlot* TitleSlot = CanvasRoot->AddChildToCanvas(TitleText);
//    TitleSlot->SetPosition(FVector2D(64.f, 16.f));
//    TitleSlot->SetAutoSize(true);
//    TitleSlot->SetZOrder(2);
//
//    ArtistNameText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ArtistNameText"));
//    ArtistNameText->SetText(FText::FromString(TEXT("Artist")));
//    UCanvasPanelSlot* NameSlot = CanvasRoot->AddChildToCanvas(ArtistNameText);
//    NameSlot->SetPosition(FVector2D(64.f, 48.f));
//    NameSlot->SetAutoSize(true);
//    NameSlot->SetZOrder(2);
//
//    GenreText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("GenreText"));
//    GenreText->SetText(FText::FromString(TEXT("Genre")));
//    GenreText->SetColorAndOpacity(FSlateColor(FLinearColor(0.f, 0.7f, 1.f, 1.f)));
//    UCanvasPanelSlot* GenreSlot = CanvasRoot->AddChildToCanvas(GenreText);
//    GenreSlot->SetPosition(FVector2D(170.f, 48.f));
//    GenreSlot->SetAutoSize(true);
//    GenreSlot->SetZOrder(2);
//
//    UTextBlock* Subtitle = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Subtitle"));
//    Subtitle->SetText(FText::FromString(TEXT("Live audition recording.")));
//    Subtitle->SetColorAndOpacity(FSlateColor(FLinearColor(0.6f, 0.6f, 0.6f, 1.f)));
//    UCanvasPanelSlot* SubtitleSlot = CanvasRoot->AddChildToCanvas(Subtitle);
//    SubtitleSlot->SetPosition(FVector2D(64.f, 80.f));
//    SubtitleSlot->SetAutoSize(true);
//    SubtitleSlot->SetZOrder(2);
//
//    const float LabelX = 64.f;
//    const float BarX = 170.f;
//    float CurrentY = 120.f;
//
//    UTextBlock* MusicalityLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("MusicalityLabel"));
//    MusicalityLabel->SetText(FText::FromString(TEXT("Musicality")));
//    MusicalityLabel->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.8f, 0.f, 1.f)));
//    UCanvasPanelSlot* MusLabelSlot = CanvasRoot->AddChildToCanvas(MusicalityLabel);
//    MusLabelSlot->SetPosition(FVector2D(LabelX, CurrentY));
//    MusLabelSlot->SetAutoSize(true);
//
//    MusicalityBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("MusicalityBar"));
//    MusicalityBar->SetFillColorAndOpacity(FLinearColor(0.f, 0.8f, 1.f, 1.f));
//    UCanvasPanelSlot* MusBarSlot = CanvasRoot->AddChildToCanvas(MusicalityBar);
//    MusBarSlot->SetPosition(FVector2D(BarX, CurrentY));
//    MusBarSlot->SetSize(FVector2D(150.f, 8.f));
//
//    CurrentY += 24.f;
//    UTextBlock* CharismaLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CharismaLabel"));
//    CharismaLabel->SetText(FText::FromString(TEXT("Charisma")));
//    CharismaLabel->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.f, 0.5f, 1.f)));
//    UCanvasPanelSlot* ChaLabelSlot = CanvasRoot->AddChildToCanvas(CharismaLabel);
//    ChaLabelSlot->SetPosition(FVector2D(LabelX, CurrentY));
//    ChaLabelSlot->SetAutoSize(true);
//
//    CharismaBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CharismaBar"));
//    CharismaBar->SetFillColorAndOpacity(FLinearColor(1.f, 0.f, 0.5f, 1.f));
//    UCanvasPanelSlot* ChaBarSlot = CanvasRoot->AddChildToCanvas(CharismaBar);
//    ChaBarSlot->SetPosition(FVector2D(BarX, CurrentY));
//    ChaBarSlot->SetSize(FVector2D(150.f, 8.f));
//
//    CurrentY += 24.f;
//    UTextBlock* CreativityLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("CreativityLabel"));
//    CreativityLabel->SetText(FText::FromString(TEXT("Creativity")));
//    CreativityLabel->SetColorAndOpacity(FSlateColor(FLinearColor(0.f, 0.7f, 1.f, 1.f)));
//    UCanvasPanelSlot* CreLabelSlot = CanvasRoot->AddChildToCanvas(CreativityLabel);
//    CreLabelSlot->SetPosition(FVector2D(LabelX, CurrentY));
//    CreLabelSlot->SetAutoSize(true);
//
//    CreativityBar = WidgetTree->ConstructWidget<UProgressBar>(UProgressBar::StaticClass(), TEXT("CreativityBar"));
//    CreativityBar->SetFillColorAndOpacity(FLinearColor(0.f, 0.7f, 1.f, 1.f));
//    UCanvasPanelSlot* CreBarSlot = CanvasRoot->AddChildToCanvas(CreativityBar);
//    CreBarSlot->SetPosition(FVector2D(BarX, CurrentY));
//    CreBarSlot->SetSize(FVector2D(150.f, 8.f));
//
//    // Now listening section
//    UImage* VinylImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("VinylImage"));
//    UCanvasPanelSlot* VinylSlot = CanvasRoot->AddChildToCanvas(VinylImage);
//    VinylSlot->SetPosition(FVector2D(BarX + 170.f, 120.f));
//    VinylSlot->SetAutoSize(true);
//
//    UTextBlock* NowListening = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("NowListening"));
//    NowListening->SetText(FText::FromString(TEXT("Now Listening: Venue Performance")));
//    UCanvasPanelSlot* NowSlot = CanvasRoot->AddChildToCanvas(NowListening);
//    NowSlot->SetPosition(FVector2D(BarX + 210.f, 120.f));
//    NowSlot->SetAutoSize(true);
//
//    // Contract section
//    CurrentY = 220.f;
//    UTextBlock* BidLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("BidLabel"));
//    BidLabel->SetText(FText::FromString(TEXT("Bid")));
//    UCanvasPanelSlot* BidLabelSlot = CanvasRoot->AddChildToCanvas(BidLabel);
//    BidLabelSlot->SetPosition(FVector2D(LabelX, CurrentY));
//    BidLabelSlot->SetAutoSize(true);
//
//    BidSlider = WidgetTree->ConstructWidget<USlider>(USlider::StaticClass(), TEXT("BidSlider"));
//    UCanvasPanelSlot* BidSliderSlot = CanvasRoot->AddChildToCanvas(BidSlider);
//    BidSliderSlot->SetPosition(FVector2D(LabelX, CurrentY + 20.f));
//    BidSliderSlot->SetSize(FVector2D(200.f, 20.f));
//
//    UTextBlock* YearsLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("YearsLabel"));
//    YearsLabel->SetText(FText::FromString(TEXT("Years")));
//    UCanvasPanelSlot* YearsLabelSlot = CanvasRoot->AddChildToCanvas(YearsLabel);
//    YearsLabelSlot->SetPosition(FVector2D(LabelX, CurrentY + 52.f));
//    YearsLabelSlot->SetAutoSize(true);
//
//    YearsSlider = WidgetTree->ConstructWidget<USlider>(USlider::StaticClass(), TEXT("YearsSlider"));
//    UCanvasPanelSlot* YearsSliderSlot = CanvasRoot->AddChildToCanvas(YearsSlider);
//    YearsSliderSlot->SetPosition(FVector2D(LabelX, CurrentY + 72.f));
//    YearsSliderSlot->SetSize(FVector2D(200.f, 20.f));
//
//    ROIText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("ROIText"));
//    ROIText->SetText(FText::FromString(TEXT("Projected ROI")));
//    UCanvasPanelSlot* RoiSlot = CanvasRoot->AddChildToCanvas(ROIText);
//    RoiSlot->SetPosition(FVector2D(LabelX, CurrentY + 104.f));
//    RoiSlot->SetAutoSize(true);
//
//    // Buttons
//    SignButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("SignButton"));
//    SignButton->SetBackgroundColor(FLinearColor(1.f, 0.8f, 0.f, 1.f));
//    UTextBlock* SignLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("SignLabel"));
//    SignLabel->SetText(FText::FromString(TEXT("Sign Artist")));
//    SignLabel->SetColorAndOpacity(FSlateColor(FLinearColor::Black));
//    SignButton->AddChild(SignLabel);
//    UCanvasPanelSlot* SignSlot = CanvasRoot->AddChildToCanvas(SignButton);
//    SignSlot->SetPosition(FVector2D(LabelX, CurrentY + 140.f));
//    SignSlot->SetSize(FVector2D(150.f, 40.f));
//
//    PassButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PassButton"));
//    PassButton->SetBackgroundColor(FLinearColor(0.15f, 0.15f, 0.15f, 1.f));
//    UTextBlock* PassLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("PassLabel"));
//    PassLabel->SetText(FText::FromString(TEXT("Pass")));
//    PassLabel->SetColorAndOpacity(FSlateColor(FLinearColor(0.7f, 0.7f, 0.7f, 1.f)));
//    PassButton->AddChild(PassLabel);
//    UCanvasPanelSlot* PassSlot = CanvasRoot->AddChildToCanvas(PassButton);
//    PassSlot->SetPosition(FVector2D(LabelX + 158.f, CurrentY + 140.f));
//    PassSlot->SetSize(FVector2D(100.f, 40.f));
//
//    return WidgetTree->RootWidget->TakeWidget();
//}
//
