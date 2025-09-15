#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LabelDataAssets.h"
#include "ArtistGenerationLibrary.generated.h"

/** Utility functions for generating sample artists. */
UCLASS()
class LABELMANAGER_API UArtistGenerationLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Generates a collection of artists specialized in 50:ies rock with randomized attributes.
     * @param Count Number of artists to create. Defaults to 5 when invoked from Blueprints.
     */
    UFUNCTION(BlueprintCallable, Category="Artist Generation")
    static TArray<FArtistAttributes> GenerateFiftiesRockArtists(int32 Count = 5);
};

