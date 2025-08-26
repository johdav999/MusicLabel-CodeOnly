#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

class FLabelUIStyle : public FSlateStyleSet
{
public:
    FLabelUIStyle();

    static void Initialize();
    static void Shutdown();
    static const ISlateStyle& Get();
    static FName GetStyleName();

    // Colors
    FLinearColor ColorBackground;
    FLinearColor ColorPanel;
    FLinearColor ColorAccent;
    FLinearColor ColorTextDim;

    // Text styles
    FTextBlockStyle Heading;
    FTextBlockStyle TileNumber;
    FTextBlockStyle Body;

    // Padding
    FMargin StandardPadding;

private:
    static TSharedPtr<FLabelUIStyle> Instance;
};
