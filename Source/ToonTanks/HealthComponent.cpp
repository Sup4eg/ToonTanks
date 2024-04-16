// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ToonTanks/ToonTanksGameMode.h"

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
    GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
    ToonTanksGameMode = Cast<AToonTanksGameMode>(UGameplayStatics::GetGameMode(this));
}

void UHealthComponent::DamageTaken(AActor* DamagedActor,  //
    float Damage,                                         //
    const UDamageType* DamageType,                        //
    AController* Instigator,                              //
    AActor* DamageCauser)
{
    if (Damage <= 0.0f) return;
    float CurrentHealth = Health - Damage;
    Health = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);
    if (FMath::IsNearlyZero(Health) && ToonTanksGameMode)
    {
        ToonTanksGameMode->ActorDied(GetOwner());
    }
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
