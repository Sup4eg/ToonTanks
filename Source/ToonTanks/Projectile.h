// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UParticleSystemComponent;
class UCameraShakeBase;

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

    UPROPERTY(VisibleAnywhere, Category = "Combat")
    UParticleSystemComponent* ParticleSystemComponent;

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

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    UParticleSystem* HitParticles;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    USoundBase* LaunchSound;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    USoundBase* HitSound;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<UCameraShakeBase> HitCameraShakeClass;

public:
    virtual void Tick(float DeltaTime) override;
};
