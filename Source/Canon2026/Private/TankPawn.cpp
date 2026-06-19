// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"

ATankPawn::ATankPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create skeletal mesh
    TankMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TankMesh"));
    SetRootComponent(TankMesh);
}

void ATankPawn::BeginPlay()
{
    Super::BeginPlay();

    // Register Enhanced Input Mapping Context
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (ULocalPlayer* LP = PC->GetLocalPlayer())
        {
            if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
            {
                Subsystem->AddMappingContext(IMC_Default, 0);
            }
        }
    }
}

void ATankPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    UE_LOG(LogTemp, Warning, TEXT("MOVE: %s  LOOK: %s"), *MoveInput.ToString(), *LookInput.ToString());


    // Forward/back movement
    if (!MoveInput.IsZero())
    {
        FVector Forward = GetActorForwardVector() * MoveInput.Y * MoveSpeed * DeltaTime;
        AddActorWorldOffset(Forward, true);
    }

    // Rotation (left/right)
    if (!LookInput.IsZero())
    {
        FRotator Rot = GetActorRotation();
        Rot.Yaw += LookInput.X * TurnSpeed * DeltaTime;
        SetActorRotation(Rot);
    }
}

void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UE_LOG(LogTemp, Warning, TEXT("PlayerInputComponent class: %s"), *PlayerInputComponent->GetClass()->GetName());


    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Bind Enhanced Input Actions
        EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ATankPawn::Move);
        EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ATankPawn::Look);
    }
}

void ATankPawn::Move(const FInputActionValue& Value)
{
    MoveInput = Value.Get<FVector2D>();
}

void ATankPawn::Look(const FInputActionValue& Value)
{
    LookInput = Value.Get<FVector2D>();
}
