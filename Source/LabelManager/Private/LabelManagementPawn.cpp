#include "LabelManagementPawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"

ALabelManagementPawn::ALabelManagementPawn()
{
    PrimaryActorTick.bCanEverTick = false;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(SceneRoot);
    SpringArm->SetUsingAbsoluteRotation(true);
    SpringArm->SetRelativeRotation(FRotator(-60.0f, 0.0f, 0.0f));
    SpringArm->TargetArmLength = 1200.0f;
    SpringArm->bDoCollisionTest = false;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false;

    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
    MovementComponent->UpdatedComponent = SceneRoot;
    MovementComponent->MaxSpeed = 1200.0f;
    MovementComponent->Acceleration = 4096.0f;
    MovementComponent->Deceleration = 4096.0f;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

UPawnMovementComponent* ALabelManagementPawn::GetMovementComponent() const
{
    return MovementComponent;
}
