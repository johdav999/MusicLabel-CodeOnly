#include "LabelManagementGameMode.h"

#include "LabelManagementPawn.h"
#include "LabelManagementPlayerController.h"

ALabelManagementGameMode::ALabelManagementGameMode()
{
    DefaultPawnClass = ALabelManagementPawn::StaticClass();
    PlayerControllerClass = ALabelManagementPlayerController::StaticClass();
}
