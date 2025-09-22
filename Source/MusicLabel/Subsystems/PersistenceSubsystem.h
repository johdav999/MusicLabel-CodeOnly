#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PersistenceSubsystem.generated.h"

/** Handles saving and loading of game state. */
UCLASS()
class MUSICLABEL_API UPersistenceSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Save current game state. */
    UFUNCTION(BlueprintCallable, Category="Persistence")
    void SaveGameState();

    /** Load previously saved game state. */
    UFUNCTION(BlueprintCallable, Category="Persistence")
    void LoadGameState();

    /** Migrate save files to a new version. */
    UFUNCTION(BlueprintCallable, Category="Persistence")
    void MigrateSaveVersion(int32 FromVersion);
};

