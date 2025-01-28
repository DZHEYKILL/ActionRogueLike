// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SGameplayInterface.h"

#include "SItemaChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASItemaChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
	void Interact_Implementation(APawn* InstigatorPawn);

public:	
	// Sets default values for this actor's properties
	ASItemaChest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Box;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Hat;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
