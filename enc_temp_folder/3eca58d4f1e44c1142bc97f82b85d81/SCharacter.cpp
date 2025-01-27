// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SptingArmComponent");
	SpringArmComp->SetupAttachment(GetRootComponent());
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(SpringArmComp);

	CameraArrow = CreateDefaultSubobject<UArrowComponent>("ArrowCamera");
	CameraArrow->SetupAttachment(SpringArmComp);
	CameraArrow->SetRelativeLocation(FVector(400.0f, 0.0f, -20.0f));
	CameraArrow->GetComponentRotation();
	CameraArrow->bHiddenInGame = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);


	PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::Turn);


	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &ASCharacter::Jump);


}

void ASCharacter::MoveForward(float Input)
{

	/*
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;
	*/

	CameraForwardVector = CameraArrow->GetForwardVector();
	CameraForwardVector.Z = 0.0f;
	CameraForwardVector.Normalize();

	AddMovementInput(CameraForwardVector, Input, false);
}

void ASCharacter::MoveRight(float Input)
{
	/*
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;
	FVector RightVector = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y);
	*/


	CameraRightVector = CameraArrow->GetRightVector();
	AddMovementInput(CameraRightVector, Input, false);
}

void ASCharacter::LookUp(float Input)
{
	AddControllerPitchInput(Input);
}

void ASCharacter::Turn(float Input)
{
	AddControllerYawInput(Input);
}

