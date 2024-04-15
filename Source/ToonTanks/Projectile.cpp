// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

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
    UE_LOG(LogTemp, Warning, TEXT("On hit!"));
    UE_LOG(LogTemp, Warning, TEXT("Hit component: %s"), *HitComponent->GetName());
    UE_LOG(LogTemp, Warning, TEXT("Ohter actor: %s"), *OtherActor->GetName());
    UE_LOG(LogTemp, Warning, TEXT("Other component: %s"), *OtherComp->GetName());
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
