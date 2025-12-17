// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();
	/*
	FVector myVector = FVector(1.0f, 1.0f, 1.0f);
	FVector* vectorPointer = &myVector;
	vectorPointer->X = 11.0f;

	UE_LOG(LogTemp, Display, TEXT("X: %f  Y: %f  Z: %f"), vectorPointer->X, myVector.Y, vectorPointer->Z);
	*/

	
	startLocation = GetOwner()->GetActorLocation();
	targetLocation = startLocation + moveOffset;

}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	

	if (shouldMove == true) {
		
		// Target location will be startLocation + MoveOffset;
		targetLocation = startLocation + moveOffset;
	}
	else {
		// Target location will be startLocation;
		targetLocation = startLocation;
	}

	FVector currentLocation = GetOwner()->GetActorLocation();
	float speed = moveOffset.Length() / moveTime;
	FVector newLocation = FMath::VInterpConstantTo(currentLocation, targetLocation, DeltaTime, speed);
	GetOwner()->SetActorLocation(newLocation);
}

