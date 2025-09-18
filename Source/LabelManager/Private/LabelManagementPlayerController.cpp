#include "LabelManagementPlayerController.h"

#include "GameFramework/Pawn.h"
#include "Math/RotationMatrix.h"

ALabelManagementPlayerController::ALabelManagementPlayerController()
{
    bEnableClickEvents = true;
    bShowMouseCursor = true;
}

void ALabelManagementPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    check(InputComponent);

    InputComponent->BindAxis(TEXT("MoveForward"), this, &ALabelManagementPlayerController::MoveForward);
    InputComponent->BindAxis(TEXT("MoveRight"), this, &ALabelManagementPlayerController::MoveRight);
}

void ALabelManagementPlayerController::MoveForward(float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        if (APawn* ControlledPawn = GetPawn())
        {
            const FRotator ControlRotation(0.0f, GetControlRotation().Yaw, 0.0f);
            const FVector Direction = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);
            ControlledPawn->AddMovementInput(Direction, Value);
        }
    }
}

void ALabelManagementPlayerController::MoveRight(float Value)
{
    if (!FMath::IsNearlyZero(Value))
    {
        if (APawn* ControlledPawn = GetPawn())
        {
            const FRotator ControlRotation(0.0f, GetControlRotation().Yaw, 0.0f);
            const FVector Direction = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::Y);
            ControlledPawn->AddMovementInput(Direction, Value);
        }
    }
}
