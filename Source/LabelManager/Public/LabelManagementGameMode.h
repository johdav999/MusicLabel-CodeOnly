#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LabelManagementGameMode.generated.h"

/**
 * Game mode that configures the label management experience.
 */
UCLASS()
class LABELMANAGER_API ALabelManagementGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ALabelManagementGameMode();
};
