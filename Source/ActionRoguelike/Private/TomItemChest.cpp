// Fill out your copyright notice in the Description page of Project Settings.


#include "TomItemChest.h"

void ATomItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	ITomGameplayInterface::Interact_Implementation(InstigatorPawn);

	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

// Sets default values
ATomItemChest::ATomItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);
}

// Called when the game starts or when spawned
void ATomItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATomItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

