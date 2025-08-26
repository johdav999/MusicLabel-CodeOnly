#pragma once

#include "CoreMinimal.h"
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

/** Basic definition of a game event. */
USTRUCT(BlueprintType)
struct FGameEvent
{
    GENERATED_BODY()

    /** Text describing the event. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Event")
    FString Description;

    /** Priority used to order events; higher values handled first. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Event")
    int32 Priority = 0;
};

