// Fill out your copyright notice in the Description page of Project Settings.


#include "TomExplosiveBarrel.h"

#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ATomExplosiveBarrel::ATomExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("Radial Force");
	RadialForceComp->SetupAttachment(StaticMeshComp);
}

// Called when the game starts or when spawned
void ATomExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
	StaticMeshComp->SetSimulatePhysics(true);
	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMeshComp->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
	StaticMeshComp->OnComponentHit.AddDynamic(this, &ATomExplosiveBarrel::OnStaticMeshHit);

	RadialForceComp->ImpulseStrength = 100000.f;
}

void ATomExplosiveBarrel::OnStaticMeshHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComp->FireImpulse();
}

// Called every frame
void ATomExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

