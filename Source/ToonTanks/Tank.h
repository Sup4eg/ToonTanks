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

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USpringArmComponent* SpringArmComponent;
};
