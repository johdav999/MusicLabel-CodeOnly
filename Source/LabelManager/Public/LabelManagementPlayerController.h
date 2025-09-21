#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LabelManagementPlayerController.generated.h"

/**
 * Player controller responsible for moving the label management pawn with keyboard input.
 */
UCLASS()
class LABELMANAGER_API ALabelManagementPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ALabelManagementPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    /** Handles forward/backward motion using the assigned pawn. */
    void MoveForward(float Value);

    /** Handles left/right motion using the assigned pawn. */
    void MoveRight(float Value);
};
