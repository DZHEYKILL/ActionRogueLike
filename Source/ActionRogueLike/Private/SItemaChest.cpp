// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemaChest.h"


// Sets default values
ASItemaChest::ASItemaChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UStaticMeshComponent>("Box");
	RootComponent = Box;

	Hat = CreateDefaultSubobject<UStaticMeshComponent>("Hat");
	Hat->SetupAttachment(Box);
}

// Called when the game starts or when spawned
void ASItemaChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASItemaChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASItemaChest::Interact_Implementation(APawn* InstigatorPawn)
{

}

