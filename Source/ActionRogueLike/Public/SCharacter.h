// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/ArrowComponent.h"
#include "TimerManager.h"
#include "SInteractionComponent.h"

#include "SCharacter.generated.h"



UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TSubclassOf<AActor> ProjectileClass;


public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UArrowComponent* CameraArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	FVector CameraForwardVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	FVector CameraRightVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USInteractionComponent* InteractComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	UAnimMontage* AttackAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FTimerHandle TimerHandle_PrimaryAttack;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Movement
	void MoveForward(float Input);
	void MoveRight(float Input);

	void LookUp(float Input);
	void Turn(float Input);
	
	//Combat
	void PrimaryAttack();
	void PrimaryInteract();
	void PrimaryAttack_TimeElapsed();

	//Geters
	FVector GetCameraForward();
};
