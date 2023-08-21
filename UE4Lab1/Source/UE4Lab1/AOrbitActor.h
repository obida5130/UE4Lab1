// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AOrbitActor.generated.h"



UCLASS()
class UE4LAB1_API AAOrbitActor : public ABaseActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAOrbitActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround");
	AActor* RotateAroundActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround");
	float rotationSpeed= 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround");
	FVector RotationRadius = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround");
	FVector RotationAxis = FVector::UpVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateAround", meta=(ClampMin="0.0",ClampMax= "360.0", UIMin="0.0", UIMax="360.0"));
	float InitialRotationAgle = 0.0f;
	float CurrentAngle = 0.0f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void reset();
};
