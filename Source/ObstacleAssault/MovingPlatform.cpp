// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	distanceFromStart = GetDistanceMoved();

	if (distanceFromStart >= moveDistance)
	{
		float overshoot = distanceFromStart - moveDistance;
		UE_LOG(LogTemp, Display, TEXT("%s overshot by %f"), *GetName(), overshoot);

		FVector moveDirection = platformVelocity.GetSafeNormal();
		FVector newStartLocation = startLocation + moveDirection * moveDistance;
		SetActorLocation(newStartLocation);
		startLocation = newStartLocation;

		platformVelocity = -platformVelocity;
	}
	else
	{
		FVector currentLocation = GetActorLocation();

		currentLocation = currentLocation + platformVelocity * DeltaTime;

		SetActorLocation(currentLocation);
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotates the platform independantly from frame rate

	AddActorLocalRotation(rotationVelocity * DeltaTime);

}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(startLocation, GetActorLocation());
}

