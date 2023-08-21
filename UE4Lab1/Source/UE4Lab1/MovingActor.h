// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BaseActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class UE4LAB1_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingActor();
	UPROPERTY(EditInstanceOnly, Category = "Movement Point");
	AActor* FirstPoint;
	UPROPERTY(EditInstanceOnly, Category = "Movement Point");
	AActor* SecondPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AActor* CurrentPoint;
	void MoveToNextPoint();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
