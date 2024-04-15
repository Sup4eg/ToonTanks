// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
    GENERATED_BODY()

public:
    AProjectile();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere, Category = "Combat")
    UStaticMeshComponent* ProjectileMesh;

    UPROPERTY(VisibleAnywhere, Category = "Movement")
    UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    float InitialSpeed = 1300.f;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    float MaxSpeed = 1300.f;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent,  //
        AActor* OtherActor,                        //
        UPrimitiveComponent* OtherComp,            //
        FVector NormalImpulse,                     //
        const FHitResult& Hit);

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    float Damage = 50.f;

public:
    virtual void Tick(float DeltaTime) override;
};
