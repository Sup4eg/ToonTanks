// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/DamageType.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
    RootComponent = ProjectileMesh;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
    ProjectileMovement->InitialSpeed = InitialSpeed;
    ProjectileMovement->MaxSpeed = MaxSpeed;
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();

    ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent,  //
    AActor* OtherActor,                                     //
    UPrimitiveComponent* OtherComp,                         //
    FVector NormalImpulse,                                  //
    const FHitResult& Hit)
{
    auto MyOwner = GetOwner();
    if (!MyOwner)
    {
        Destroy();
        return;
    }

    auto MyOwnerInstigator = MyOwner->GetInstigatorController();
    auto DamageTypeClass = UDamageType::StaticClass();

    if (OtherActor && OtherActor != this && OtherActor != MyOwner)
    {
        UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
        if (HitParticles)
        {
            UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());
        }
    }
    Destroy();
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
