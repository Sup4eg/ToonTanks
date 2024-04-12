// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"

ABasePawn::ABasePawn()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ABasePawn::BeginPlay()
{
    Super::BeginPlay();
}

void ABasePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
