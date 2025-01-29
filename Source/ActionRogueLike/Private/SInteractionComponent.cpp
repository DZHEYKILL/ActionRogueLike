// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USInteractionComponent::PrimaryInteract()
{
	AActor* Owner = GetOwner();
	FVector EyeLocation;
	FRotator EyeRotation;
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);


	//FHitResult Hit;
	TArray<FHitResult> Hits;
	FCollisionShape Shape;
	Shape.SetSphere(30.0f);
	FVector Start = Owner->GetActorLocation();
	FVector End = EyeLocation + (EyeRotation.Vector()*1000);	//Character->GetCameraForward();//(MyOwner->GetActorLocation() + MyOwner->GetActorForwardVector()) * 400;
	
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	/*
	bool bBlockingHit = GetWorld()->LineTraceSingleByObjectType(
			Hit,
			EyeLocation,
			End,
			ObjectQueryParams
		);
	
	*/
	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(
		Hits, 
		EyeLocation,
		End, 
		FQuat::Identity,
		ObjectQueryParams,
		Shape
		);
	FColor LineColor = bBlockingHit ? FColor::Green : FColor::Red;
	
	for (FHitResult Hit : Hits)
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor && HitActor->Implements<USGameplayInterface>())
		{

			APawn* MyPawn = Cast<APawn>(Owner);

			ISGameplayInterface::Execute_Interact(HitActor, MyPawn);
		
		};

		DrawDebugSphere(GetWorld(), Hit.ImpactPoint, 30.0f, 32, LineColor, false, 2.0f);
	}

	
	DrawDebugLine(GetWorld(), EyeLocation, End, LineColor, false, 2.0f, 0, 2.0f);

	
}

