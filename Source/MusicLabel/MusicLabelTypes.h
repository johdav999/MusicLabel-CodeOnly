#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MusicLabelTypes.generated.h"

/** Represents a financial transaction in the game's economy. */
USTRUCT(BlueprintType)
struct FTransaction
{
    GENERATED_BODY()

    /** Description of the transaction. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transaction")
    FString Description;

    /** Monetary value of the transaction. Positive for revenue, negative for expense. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transaction")
    float Amount = 0.0f;
};

/** Data describing an artist tour. */
USTRUCT(BlueprintType)
struct FTour
{
    GENERATED_BODY()

    /** Name of the tour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tour")
    FString Name;

    /** Cities or venues to visit during the tour. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tour")
    TArray<FString> Stops;
};

UENUM(BlueprintType)
enum class EEventCategory : uint8
{
    NewArtistGigging      UMETA(DisplayName="New Artist Gigging (to scout)"),
    ArtistSignedRecordDeal UMETA(DisplayName="Artist Signed a record Deal"),
    ArtistBookedForTour   UMETA(DisplayName="Artist Booked for a tour"),
    NewGenreEmerged       UMETA(DisplayName="New Genre has emerged")
};

/** Definition of an event entry for data tables. */
USTRUCT(BlueprintType)
struct FGameEvent : public FTableRowBase
{
    GENERATED_BODY()

    /** Short headline for the event. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Event")
    FString Headline;

    /** When the event occurred. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Event")
    FDateTime Date;

    /** Detailed description of the event. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Event")
    FString Description;

    /** Category of the event. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Event")
    EEventCategory EventCategory = EEventCategory::NewArtistGigging;
};

/** Represents a single piece of music. */
USTRUCT(BlueprintType)
struct FSong
{
    GENERATED_BODY()

    /** Title of the song. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Song")
    FString Title;

    /** Length of the song in seconds. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Song")
    int32 LengthSec = 0;

    /** Tempo of the song in beats per minute. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Song")
    int32 TempoBPM = 0;
};

