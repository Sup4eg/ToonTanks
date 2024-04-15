// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"
#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"

ABasePawn::ABasePawn()
{
    PrimaryActorTick.bCanEverTick = true;
    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
    RootComponent = CapsuleComponent;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
    BaseMesh->SetupAttachment(CapsuleComponent);

    TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>("TurretMesh");
    TurretMesh->SetupAttachment(BaseMesh);

    ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>("ProjectileSpawnPoint");
    ProjectileSpawnPoint->SetupAttachment(TurretMesh);

    HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{

    FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
    FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
    TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(),  //
        LookAtRotation,                                                                //
        UGameplayStatics::GetWorldDeltaSeconds(this),                                  //
        15.f));
}

void ABasePawn::Fire()
{
    DrawDebugSphere(GetWorld(),                        //
        ProjectileSpawnPoint->GetComponentLocation(),  //
        25.f,                                          //
        12,                                            //
        FColor::Red,                                   //
        false,                                         //
        3.f);

    GetWorld()->SpawnActor<AProjectile>(ProjectileClass,  //
        ProjectileSpawnPoint->GetComponentLocation(),     //
        ProjectileSpawnPoint->GetComponentRotation());
}
