// Fill out your copyright notice in the Description page of Project Settings.


#include "AOrbitActor.h"

// Sets default values
AAOrbitActor::AAOrbitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAOrbitActor::BeginPlay()
{
	Super::BeginPlay();
	reset();
	
}

void AAOrbitActor::reset() {
	CurrentAngle = InitialRotationAgle;
	if (RotateAroundActor == NULL) {
		return;
	}

	if (RotationRadius.IsZero()) {
		RotationRadius = GetActorLocation() - RotateAroundActor->GetActorLocation();
	}
};

// Called every frame
void AAOrbitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RotateAroundActor) {
		CurrentAngle += rotationSpeed * DeltaTime;
	}
	if (CurrentAngle > 360.0f) {
		CurrentAngle -=360.0f;
	}

	FVector NewLocation = RotateAroundActor->GetActorLocation() +  RotationRadius.RotateAngleAxis(CurrentAngle, RotationAxis);

	this->SetActorLocation(NewLocation);

}

