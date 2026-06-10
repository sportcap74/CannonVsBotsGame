// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCannon.h"

// Sets default values
APlayerCannon::APlayerCannon()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCannon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCannon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

