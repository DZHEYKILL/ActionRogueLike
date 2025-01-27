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
	CameraArrow->SetRelativeLocation(FVector(300.0f, 0.0f, -100.0f));
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

	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &ASCharacter::Jump);

	PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::Turn);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ASCharacter::PrimaryAttack);


}

void ASCharacter::MoveForward(float Input)
{
	FVector CameraForwardVectorM = CameraForwardVector;
	CameraForwardVectorM.Z = 0.0f;
	CameraForwardVectorM.Normalize();
	/* ѕосле обнулени€ Z компоненты вектор может стать неединичным 
	(его длина может быть меньше или больше 1). 
	ƒл€ корректной работы системы движени€ (AddMovementInput),
	вектор должен быть нормализован, чтобы его длина всегда была равна 1.
	Ёто делаетс€ вызовом CameraForwardVector.Normalize();.*/

	AddMovementInput(CameraForwardVectorM, Input, false);
	/*
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;
	*/
}

void ASCharacter::MoveRight(float Input)
{
	AddMovementInput(CameraRightVector, Input, false);
	/*
	FRotator ControlRotation = GetControlRotation();
	ControlRotation.Pitch = 0.0f;
	ControlRotation.Roll = 0.0f;
	FVector RightVector = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y);
	*/
}

void ASCharacter::LookUp(float Input)
{
	CameraForwardVector = CameraArrow->GetForwardVector();
	CameraRightVector = CameraArrow->GetRightVector();

	AddControllerPitchInput(Input);
}
void ASCharacter::Turn(float Input)
{
	CameraForwardVector = CameraArrow->GetForwardVector();
	CameraRightVector = CameraArrow->GetRightVector();

	AddControllerYawInput(Input);
}
void ASCharacter::PrimaryAttack()
{
	FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_01");

	FTransform SpawnTM = FTransform(GetControlRotation(), HandLocation);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	
	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);
}

