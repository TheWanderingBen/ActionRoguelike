// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TomGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "TomItemChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ATomItemChest : public AActor, public ITomGameplayInterface
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere)
	float TargetPitch;
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

	// Sets default values for this actor's properties
	ATomItemChest();
protected:
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
