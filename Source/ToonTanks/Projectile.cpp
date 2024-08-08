// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "GameFramework/DamageType.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraShakeBase.h"
#include "Engine/World.h"

AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
    RootComponent = ProjectileMesh;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
    ProjectileMovement->InitialSpeed = InitialSpeed;
    ProjectileMovement->MaxSpeed = MaxSpeed;

    ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComponent");
    ParticleSystemComponent->SetupAttachment(RootComponent);
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();

    ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

    if (LaunchSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
    }
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

    AController* MyOwnerInstigator = MyOwner->GetInstigatorController();
    UClass* DamageTypeClass = UDamageType::StaticClass();

    if (OtherActor && OtherActor != this && OtherActor != MyOwner)
    {
        if (HitSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
        }
        UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
        if (HitParticles)
        {
            UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());
        }
        if (HitCameraShakeClass)
        {
            GetWorld()->GetFirstPlayerController()->PlayerCameraManager->StartCameraShake(HitCameraShakeClass);
        }
    }
    Destroy();
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
