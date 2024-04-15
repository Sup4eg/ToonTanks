// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
    GENERATED_BODY()

public:
    ABasePawn();

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* BaseMesh;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* TurretMesh;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USceneComponent* ProjectileSpawnPoint;

public:
    virtual void Tick(float DeltaTime) override;
};
