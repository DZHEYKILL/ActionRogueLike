// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/RadialForceComponent.h"

#include "SExplosionBarell.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASExplosionBarell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosionBarell();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Barrel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	URadialForceComponent* RadialForce;

	UFUNCTION(BlueprintCallable)
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
