// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Components/StaticMeshComponent.h"

AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
    RootComponent = ProjectileMesh;
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
