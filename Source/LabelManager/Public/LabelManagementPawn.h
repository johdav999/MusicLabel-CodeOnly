#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "LabelManagementPawn.generated.h"

class USceneComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;

/**
 * Pawn that provides a top-down style camera for the label management experience.
 */
UCLASS()
class LABELMANAGER_API ALabelManagementPawn : public APawn
{
    GENERATED_BODY()

public:
    ALabelManagementPawn();
    virtual UPawnMovementComponent* GetMovementComponent() const override;

protected:
    /** Root component for the pawn hierarchy. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* SceneRoot;

    /** Arm used to offset the camera from the pawn origin. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArm;

    /** Camera providing an overview of the label management area. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* Camera;

    /** Handles simple planar movement for the pawn. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UFloatingPawnMovement* MovementComponent;
};
