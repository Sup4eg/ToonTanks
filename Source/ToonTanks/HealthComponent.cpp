// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    Health = MaxHealth;
    GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
}

void UHealthComponent::DamageTaken(AActor* DamagedActor,  //
    float Damage,                                         //
    const UDamageType* DamageType,                        //
    AController* Instigator,                              //
    AActor* DamageCauser)
{
    if (Damage <= 0.0f) return;
    Health -= Damage;
    UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
