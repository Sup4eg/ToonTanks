// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class UCapsuleComponent;
class AProjectile;

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
    GENERATED_BODY()

public:
    ABasePawn();

protected:
    void RotateTurret(FVector LookAtTarget);

    void Fire();

private:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* BaseMesh;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* TurretMesh;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USceneComponent* ProjectileSpawnPoint;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<AProjectile> ProjectileClass;
};
