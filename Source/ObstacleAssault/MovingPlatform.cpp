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

	int myInt = 33;
	UE_LOG(LogTemp, Display, TEXT("My Int: %d"), myInt);

	float myFloat = 3.14f;
	UE_LOG(LogTemp, Display, TEXT("My float is %f"), myFloat);

	FString myString = "Custom String";
	UE_LOG(LogTemp, Display, TEXT("My string is %s"), *myString);

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

