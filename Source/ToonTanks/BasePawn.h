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

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    int32 VisibleAnywhereInt = 12;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    int32 EditAnywhereInt = 22;

    UPROPERTY(VisibleInstanceOnly)
    int32 VisibleInstanceOnlyInt = 32;

    UPROPERTY(VisibleDefaultsOnly)
    int32 VisibleDefaultsOnlyInt = 5;

    UPROPERTY(EditDefaultsOnly)
    int32 EditDefaultsOnlyInt = 9;

    UPROPERTY(EditInstanceOnly)
    int32 EditOnlyInstanceInt = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Speed = 400.f;

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UCapsuleComponent* CapsuleComponent;

    UPROPERTY()
    UStaticMeshComponent* BaseMesh;

    UPROPERTY()
    UStaticMeshComponent* TurretMesh;

    UPROPERTY()
    USceneComponent* ProjectileSpawnPoint;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
