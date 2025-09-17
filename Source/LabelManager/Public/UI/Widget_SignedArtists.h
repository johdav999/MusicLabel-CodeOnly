#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_SignedArtists.generated.h"

class UVerticalBox;
class UHorizontalBox;
class UBorder;
class UWidgetTree;

USTRUCT(BlueprintType)
struct FSignedArtistRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signed Artists")
    FText ArtistName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signed Artists")
    FText Genres;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signed Artists")
    int32 ContractsSigned = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signed Artists")
    int32 AlbumsRecorded = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signed Artists")
    FText FanCount;
};

UCLASS(BlueprintType)
class LABELMANAGER_API UWidget_SignedArtists : public UUserWidget
{
    GENERATED_BODY()

public:
    UWidget_SignedArtists(const FObjectInitializer& ObjectInitializer);

    virtual TSharedRef<SWidget> RebuildWidget() override;

    UFUNCTION(BlueprintCallable, Category = "Signed Artists")
    void SetArtistRows(const TArray<FSignedArtistRow>& InRows);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Signed Artists")
    TArray<FSignedArtistRow> ArtistRows;

private:
    void BuildDefaultRows();
    void BuildLayout();
    void BuildHeaderRow(UVerticalBox* ParentBox);
    void BuildArtistRows(UVerticalBox* ParentBox);

    void AddRowBackground(UVerticalBox* ParentBox, UHorizontalBox* RowContent, bool bIsHeader, bool bIsEvenRow);
    UHorizontalBox* CreateHeaderRow();
    UHorizontalBox* CreateArtistRow(const FSignedArtistRow& RowData);

    void AddColumn(UHorizontalBox* Row,
        const FText& Text,
        float FillWeight,
        EHorizontalAlignment HAlign,
        ETextJustify::Type Justify,
        const FLinearColor& Color,
        int32 FontSize,
        const FMargin& Padding,
        float LetterSpacing = 0.f,
        bool bBold = false);
};
