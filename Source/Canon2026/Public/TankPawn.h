// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"            // <-- Måste ligga före generated.h
#include "TankPawn.generated.h"

class UInputAction;
class UInputMappingContext;
class USkeletalMeshComponent;

UCLASS()
class CANON2026_API ATankPawn : public APawn
{
    GENERATED_BODY()

public:
    ATankPawn();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Skeletal mesh component for the tank body
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank")
    USkeletalMeshComponent* TankMesh;

    // Movement input values
    FVector2D MoveInput;
    FVector2D LookInput;

    // Movement speed
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
    float MoveSpeed = 300.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tank")
    float TurnSpeed = 100.f;

    // Enhanced Input: Mapping Context
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* IMC_Default;

    // Enhanced Input: Input Actions
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* IA_Move;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* IA_Look;

    // Input callbacks
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
};
