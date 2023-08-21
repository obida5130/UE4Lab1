// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

// Sets default values
AMovingActor::AMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	MoveToNextPoint();
	
}

void AMovingActor::MoveToNextPoint() {
	if (CurrentPoint == NULL || CurrentPoint == SecondPoint) {
		CurrentPoint = FirstPoint;
	}
	else {
		CurrentPoint = SecondPoint;
	}
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FirstPoint == NULL || SecondPoint == NULL) {
		return;
	}

	if (CurrentPoint != NULL) {
		FVector delta = GetActorLocation() - CurrentPoint->GetActorLocation();
		float distance = delta.Size();
		
		if (distance < 100.0f) {
			MoveToNextPoint();
		}
		delta.Normalize();

		FRotator NewLookAt = FRotationMatrix::MakeFromX(delta).Rotator();
		NewLookAt.Pitch = 0.0f;
		NewLookAt.Roll = 0.0f;
		NewLookAt.Yaw += -180.0f;

		this->SetActorRotation(FMath::Lerp(FQuat(this->GetActorRotation()), FQuat(NewLookAt), 0.03f));
		this->SetActorLocation(FMath::Lerp(this->GetActorLocation(), CurrentPoint->GetActorLocation(), 0.01f));
	}

	

}

