// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// A test function
void MyTestFunction(float myFloatParam, FString myStringParam)
{
	UE_LOG(LogTemp, Display, TEXT("My Float Param is %f"), myFloatParam);

	UE_LOG(LogTemp, Display, TEXT("My String Param is %s"), *myStringParam);

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	FString myName = GetName();
	MyTestFunction(3.14f, myName);

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
	FVector currentLocation = GetActorLocation();

	currentLocation = currentLocation + (platformVelocity * DeltaTime);

	SetActorLocation(currentLocation);

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotates the platform independantly from frame rate

}

