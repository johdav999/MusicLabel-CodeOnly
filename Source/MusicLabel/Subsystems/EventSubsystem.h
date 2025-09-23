#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TimerManager.h"
#include "EventSubsystem.generated.h"


class ULayout;
struct FGameEvent;

/** Manages random or triggered game events. */
UCLASS()
class MUSICLABEL_API UEventSubsystem : public UGameInstanceSubsystem {
  GENERATED_BODY()
public:
  virtual void Initialize(FSubsystemCollectionBase &Collection) override;

  /** Trigger an immediate event. */
  UFUNCTION(BlueprintCallable, Category = "Events")
  void TriggerEvent(const FGameEvent &Event);

  /** Resolve the next event in the queue. */
  UFUNCTION(BlueprintCallable, Category = "Events")
  void ResolveEvent();

  /** Schedule a future event. */
  UFUNCTION(BlueprintCallable, Category = "Events")
  void ScheduleEvent(const FGameEvent &Event);

  /** Queue an event to be surfaced by the timed generator. */
  UFUNCTION(BlueprintCallable, Category = "Events")
  void AddPendingEvent(const FGameEvent &Event);

private:
  /** Generate the next pending event. */
  void GenerateNextEvent();

  /** Queue of pending events. */
  TArray<FGameEvent> EventQueue;

  /** Events waiting to be triggered on a timer. */
  TArray<FGameEvent> PendingEvents;

  /** Timer handle for periodic event generation. */
  FTimerHandle EventTimer;

  /** Cached reference to the main layout widget. */
  UPROPERTY()
  ULayout *LayoutWidget = nullptr;
};
