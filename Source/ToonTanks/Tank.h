// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
    GENERATED_BODY()

public:
    ATank();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    float Speed = 200.f;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    float TurnRate = 150.f;

    void Move(float Value);

    void Turn(float Value);

    APlayerController* PlayerControllerRef;
};