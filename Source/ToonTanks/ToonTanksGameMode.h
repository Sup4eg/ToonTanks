// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

class ATank;
class AToonTanksPlayerController;

UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    void ActorDied(AActor* DeadActor);

protected:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintImplementableEvent)
    void StartGame();

private:
    ATank* Tank;
    AToonTanksPlayerController* ToonTanksPlayerController;

    float StartDelay = 3.0f;

    void HandleGameStart();
};
