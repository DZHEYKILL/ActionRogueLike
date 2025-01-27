// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosionBarell.h"

// Sets default values
ASExplosionBarell::ASExplosionBarell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	RootComponent = Box;
	Box->SetCollisionObjectType(ECC_PhysicsBody);
	Box->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Ignore);
	Box->OnComponentHit.AddDynamic(this, &ASExplosionBarell::OnComponentHit);
	Box->SetSimulatePhysics(true);
	Barrel = CreateDefaultSubobject<UStaticMeshComponent>("Barrel");
	Barrel->SetCollisionObjectType(ECC_PhysicsBody);
	Barrel->SetupAttachment(Box);
	Barrel->SetSimulatePhysics(true);

	RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForce->SetupAttachment(Box); // Привязываем к Box
	RadialForce->Radius = 500.f; // Устанавливаем радиус воздействия
	RadialForce->ForceStrength = 1000.f; // Устанавливаем силу воздействия
	RadialForce->bImpulseVelChange = true; // Включаем изменение скорости
	RadialForce->bAutoActivate = false; // Отключаем автоматическое срабатывание


}


// Called when the game starts or when spawned
void ASExplosionBarell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASExplosionBarell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASExplosionBarell::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	RadialForce->FireImpulse();

};

