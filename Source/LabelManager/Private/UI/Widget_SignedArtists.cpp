#include "UI/Widget_SignedArtists.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
//#include "Layout/SlateChildSize.h"

#define LOCTEXT_NAMESPACE "WidgetSignedArtists"

namespace
{
    constexpr float HeaderLetterSpacing = 80.f;
    constexpr float TitleLetterSpacing = 140.f;
    constexpr int32 TitleFontSize = 36;
    constexpr int32 HeaderFontSize = 14;
    constexpr int32 ArtistFontSize = 20;
    constexpr int32 DetailFontSize = 18;
}

UWidget_SignedArtists::UWidget_SignedArtists(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    BuildDefaultRows();
}

TSharedRef<SWidget> UWidget_SignedArtists::RebuildWidget()
{
    BuildDefaultRows();

    if (!WidgetTree)
    {
        WidgetTree = NewObject<UWidgetTree>(this, TEXT("WidgetTree"));
    }

    if (WidgetTree)
    {
        WidgetTree->RootWidget = nullptr;
    }

    BuildLayout();

    if (WidgetTree && WidgetTree->RootWidget)
    {
        return WidgetTree->RootWidget->TakeWidget();
    }

    return Super::RebuildWidget();
}

void UWidget_SignedArtists::SetArtistRows(const TArray<FSignedArtistRow>& InRows)
{
    ArtistRows = InRows;
    if (ArtistRows.Num() == 0)
    {
        BuildDefaultRows();
    }

    if (WidgetTree && WidgetTree->RootWidget)
    {
        BuildLayout();
    }
}

void UWidget_SignedArtists::BuildDefaultRows()
{
    if (ArtistRows.Num() > 0)
    {
        return;
    }

    ArtistRows.Add({
        LOCTEXT("ArtistRoland", "ROLAND"),
        LOCTEXT("RolandGenre", "R&R / ROCK"),
        2,
        1,
        LOCTEXT("RolandFans", "201K")
    });

    ArtistRows.Add({
        LOCTEXT("ArtistEvelyn", "EVELYN Z"),
        LOCTEXT("EvelynGenre", "R&B / POP"),
        1,
        1,
        LOCTEXT("EvelynFans", "314K")
    });

    ArtistRows.Add({
        LOCTEXT("ArtistBadheard", "BADHEARD"),
        LOCTEXT("BadheardGenre", "HIP-HOP / R&B"),
        3,
        2,
        LOCTEXT("BadheardFans", "1031K")
    });

    ArtistRows.Add({
        LOCTEXT("ArtistMelodyDash", "MELODY DASH"),
        LOCTEXT("MelodyGenre", "POP / JAZZ"),
        4,
        3,
        LOCTEXT("MelodyFans", "4201K")
    });

    ArtistRows.Add({
        LOCTEXT("ArtistStereous", "STEREOUS"),
        LOCTEXT("StereousGenre", "ELECTRONIC / DUBSTEP"),
        2,
        2,
        LOCTEXT("StereousFans", "102K")
    });

    ArtistRows.Add({
        LOCTEXT("ArtistAlexTheo", "ALEX THEO"),
        LOCTEXT("AlexGenre", "R&R / ROCK"),
        1,
        1,
        LOCTEXT("AlexFans", "235K")
    });
}

void UWidget_SignedArtists::BuildLayout()
{
    if (!WidgetTree)
    {
        return;
    }

    UCanvasPanel* RootCanvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("CanvasRoot"));
    WidgetTree->RootWidget = RootCanvas;

    UBorder* BackgroundBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("Background"));
    BackgroundBorder->SetBrushColor(FLinearColor(0.01f, 0.01f, 0.01f, 0.95f));
    BackgroundBorder->SetPadding(FMargin(32.f, 36.f));

    if (UCanvasPanelSlot* BackgroundSlot = RootCanvas->AddChildToCanvas(BackgroundBorder))
    {
        BackgroundSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
        BackgroundSlot->SetOffsets(FMargin(0.f));
        BackgroundSlot->SetAutoSize(false);
        BackgroundSlot->SetZOrder(0);
    }

    UVerticalBox* ContentBox = WidgetTree->ConstructWidget<UVerticalBox>(UVerticalBox::StaticClass(), TEXT("Content"));
    BackgroundBorder->SetContent(ContentBox);

    UTextBlock* TitleText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("Title"));
    TitleText->SetText(LOCTEXT("SignedArtistsTitle", "SIGNED ARTISTS"));
    TitleText->SetColorAndOpacity(FSlateColor(FLinearColor(1.f, 0.82f, 0.f, 1.f)));
    FSlateFontInfo TitleFont = TitleText->GetFont();
    TitleFont.Size = TitleFontSize;
    TitleFont.LetterSpacing = TitleLetterSpacing;
    TitleFont.TypefaceFontName = FName("Bold");
    TitleText->SetFont(TitleFont);
    TitleText->SetJustification(ETextJustify::Left);

    if (UVerticalBoxSlot* TitleSlot = ContentBox->AddChildToVerticalBox(TitleText))
    {
        TitleSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 24.f));
        TitleSlot->SetHorizontalAlignment(HAlign_Left);
    }

    BuildHeaderRow(ContentBox);

    USizeBox* Divider = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("Divider"));
    Divider->SetHeightOverride(2.f);
    UBorder* DividerBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass(), TEXT("DividerBorder"));
    DividerBorder->SetBrushColor(FLinearColor(0.18f, 0.18f, 0.18f, 1.f));
    DividerBorder->SetPadding(FMargin(0.f));
    Divider->SetContent(DividerBorder);

    if (UVerticalBoxSlot* DividerSlot = ContentBox->AddChildToVerticalBox(Divider))
    {
        DividerSlot->SetPadding(FMargin(0.f, 8.f, 0.f, 12.f));
        DividerSlot->SetHorizontalAlignment(HAlign_Fill);
    }

    BuildArtistRows(ContentBox);
}

void UWidget_SignedArtists::BuildHeaderRow(UVerticalBox* ParentBox)
{
    if (!ParentBox)
    {
        return;
    }

    UHorizontalBox* HeaderRow = CreateHeaderRow();
    AddRowBackground(ParentBox, HeaderRow, true, false);
}

void UWidget_SignedArtists::BuildArtistRows(UVerticalBox* ParentBox)
{
    if (!ParentBox)
    {
        return;
    }

    for (int32 Index = 0; Index < ArtistRows.Num(); ++Index)
    {
        UHorizontalBox* Row = CreateArtistRow(ArtistRows[Index]);
        const bool bEvenRow = (Index % 2) == 0;
        AddRowBackground(ParentBox, Row, false, bEvenRow);
    }
}

void UWidget_SignedArtists::AddRowBackground(UVerticalBox* ParentBox, UHorizontalBox* RowContent, bool bIsHeader, bool bIsEvenRow)
{
    if (!ParentBox || !RowContent)
    {
        return;
    }

    UBorder* RowBorder = WidgetTree->ConstructWidget<UBorder>(UBorder::StaticClass());
    const float BaseShade = bIsHeader ? 0.06f : (bIsEvenRow ? 0.035f : 0.02f);
    RowBorder->SetBrushColor(FLinearColor(BaseShade, BaseShade, BaseShade, 1.f));
    const float VerticalPadding = bIsHeader ? 12.f : 10.f;
    RowBorder->SetPadding(FMargin(24.f, VerticalPadding, 24.f, VerticalPadding));
    RowBorder->SetContent(RowContent);

    if (UVerticalBoxSlot* RowSlot = ParentBox->AddChildToVerticalBox(RowBorder))
    {
        RowSlot->SetHorizontalAlignment(HAlign_Fill);
        RowSlot->SetPadding(bIsHeader ? FMargin(0.f, 0.f, 0.f, 6.f) : FMargin(0.f, 0.f, 0.f, 4.f));
    }
}

UHorizontalBox* UWidget_SignedArtists::CreateHeaderRow()
{
    UHorizontalBox* Row = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("HeaderRow"));
    const FLinearColor HeaderColor(0.7f, 0.7f, 0.7f, 1.f);

    AddColumn(Row, LOCTEXT("HeaderArtist", "ARTIST NAME"), 2.5f, HAlign_Left, ETextJustify::Left, HeaderColor, HeaderFontSize, FMargin(0.f, 0.f, 32.f, 0.f), HeaderLetterSpacing, true);
    AddColumn(Row, LOCTEXT("HeaderGenres", "GENRES"), 2.f, HAlign_Left, ETextJustify::Left, HeaderColor, HeaderFontSize, FMargin(0.f, 0.f, 32.f, 0.f), HeaderLetterSpacing, true);
    AddColumn(Row, LOCTEXT("HeaderSigned", "SIGNED"), 0.f, HAlign_Right, ETextJustify::Right, HeaderColor, HeaderFontSize, FMargin(0.f, 0.f, 24.f, 0.f), HeaderLetterSpacing, true);
    AddColumn(Row, LOCTEXT("HeaderRecorded", "RECORDED"), 0.f, HAlign_Right, ETextJustify::Right, HeaderColor, HeaderFontSize, FMargin(0.f, 0.f, 24.f, 0.f), HeaderLetterSpacing, true);
    AddColumn(Row, LOCTEXT("HeaderFans", "FANS"), 0.f, HAlign_Right, ETextJustify::Right, HeaderColor, HeaderFontSize, FMargin(0.f), HeaderLetterSpacing, true);

    return Row;
}

UHorizontalBox* UWidget_SignedArtists::CreateArtistRow(const FSignedArtistRow& RowData)
{
    UHorizontalBox* Row = WidgetTree->ConstructWidget<UHorizontalBox>(UHorizontalBox::StaticClass(), TEXT("ArtistRow"));
    const FLinearColor PrimaryColor(0.95f, 0.95f, 0.95f, 1.f);
    const FLinearColor SecondaryColor(0.75f, 0.75f, 0.75f, 1.f);
    const FLinearColor NumericColor(0.9f, 0.9f, 0.9f, 1.f);
    const FLinearColor HighlightColor(1.f, 0.82f, 0.f, 1.f);

    AddColumn(Row, RowData.ArtistName, 2.5f, HAlign_Left, ETextJustify::Left, PrimaryColor, ArtistFontSize, FMargin(0.f, 0.f, 32.f, 0.f), 0.f, true);
    AddColumn(Row, RowData.Genres, 2.f, HAlign_Left, ETextJustify::Left, SecondaryColor, DetailFontSize, FMargin(0.f, 0.f, 32.f, 0.f));
    AddColumn(Row, FText::AsNumber(RowData.ContractsSigned), 0.f, HAlign_Right, ETextJustify::Right, NumericColor, DetailFontSize, FMargin(0.f, 0.f, 24.f, 0.f));
    AddColumn(Row, FText::AsNumber(RowData.AlbumsRecorded), 0.f, HAlign_Right, ETextJustify::Right, NumericColor, DetailFontSize, FMargin(0.f, 0.f, 24.f, 0.f));
    AddColumn(Row, RowData.FanCount, 0.f, HAlign_Right, ETextJustify::Right, HighlightColor, DetailFontSize, FMargin(0.f));

    return Row;
}

void UWidget_SignedArtists::AddColumn(UHorizontalBox* Row,
    const FText& Text,
    float FillWeight,
    EHorizontalAlignment HAlign,
    ETextJustify::Type Justify,
    const FLinearColor& Color,
    int32 FontSize,
    const FMargin& PaddingValue,
    float LetterSpacing,
    bool bBold)
{
    if (!Row)
    {
        return;
    }

    UTextBlock* TextWidget = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
    TextWidget->SetText(Text);
    TextWidget->SetColorAndOpacity(FSlateColor(Color));
    TextWidget->SetJustification(Justify);

    FSlateFontInfo FontInfo = TextWidget->GetFont();
    FontInfo.Size = FontSize;
    FontInfo.LetterSpacing = LetterSpacing;
    if (bBold)
    {
        FontInfo.TypefaceFontName = FName("Bold");
    }
    TextWidget->SetFont(FontInfo);

    if (UHorizontalBoxSlot* BoxSlot = Row->AddChildToHorizontalBox(TextWidget))
    {
        BoxSlot->SetPadding(PaddingValue);
        BoxSlot->SetHorizontalAlignment(HAlign);
        BoxSlot->SetVerticalAlignment(VAlign_Center);

        if (FillWeight > 0.f)
        {
            FSlateChildSize FillSize;
            FillSize.SizeRule = ESlateSizeRule::Fill;
            FillSize.Value = FillWeight;
            BoxSlot->SetSize(FillSize);
        }
        else
        {
            BoxSlot->SetSize(FSlateChildSize(ESlateSizeRule::Automatic));
        }
    }
}

#undef LOCTEXT_NAMESPACE
