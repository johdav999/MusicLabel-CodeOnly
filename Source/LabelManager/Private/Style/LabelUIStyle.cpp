#include "Style/LabelUIStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/CoreStyle.h"

TSharedPtr<FLabelUIStyle> FLabelUIStyle::Instance = nullptr;

FLabelUIStyle::FLabelUIStyle()
    : FSlateStyleSet(GetStyleSetName())
{
    ColorBackground = FLinearColor(0.05f, 0.05f, 0.05f);
    ColorPanel = FLinearColor(0.1f, 0.1f, 0.1f);
    ColorAccent = FLinearColor(0.0f, 0.5f, 1.0f);
    ColorTextDim = FLinearColor(0.6f, 0.6f, 0.6f);

    Heading = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Bold", 24))
        .SetColorAndOpacity(FSlateColor(FLinearColor::White));

    TileNumber = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Bold", 32))
        .SetColorAndOpacity(FSlateColor(ColorAccent));

    Body = FTextBlockStyle()
        .SetFont(FCoreStyle::GetDefaultFontStyle("Regular", 12))
        .SetColorAndOpacity(FSlateColor(FLinearColor::White));

    StandardPadding = FMargin(8.f);
}

void FLabelUIStyle::Initialize()
{
    if (!Instance.IsValid())
    {
        Instance = MakeShared<FLabelUIStyle>();
        FSlateStyleRegistry::RegisterSlateStyle(*Instance);
    }
}

void FLabelUIStyle::Shutdown()
{
    if (Instance.IsValid())
    {
        FSlateStyleRegistry::UnRegisterSlateStyle(*Instance);
        Instance.Reset();
    }
}

const ISlateStyle& FLabelUIStyle::Get()
{
    return *Instance;
}

FName FLabelUIStyle::GetStyleSetName()
{
    static FName StyleName(TEXT("LabelUIStyle"));
    return StyleName;
}
