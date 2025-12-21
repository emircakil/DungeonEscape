// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent() {

	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Display, TEXT("Cemosi Emosi"));
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (moverActor) { //moverActor != nullptr
	
		mover = moverActor->FindComponentByClass<UMover>();

		if (mover) { //mover != nullptr
		
			UE_LOG(LogTemp, Display, TEXT("Succesfully to find mover component"));
		}
		else {
		
			UE_LOG(LogTemp, Display, TEXT("Failed to find mover component"));
		}

	}
	else {
	
		UE_LOG(LogTemp, Display, TEXT("MoverActor is null"));
	}

	if (isPressurePlate) {
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::Trigger(bool NewTriggerValue)
{
	isTriggered = NewTriggerValue;
	if (mover) {
		mover->SetShouldMove(isTriggered);
	}
	else {
		//UE_LOG(LogTemp, Display, TEXT("%s doesn't have mover to trigger!."), GetOwner()->GetActorNameOrLabel());
	}
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator")) {
		activatorCount++;
		if (!isTriggered) {
			Trigger(true);
		}
	}
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator")) {
		activatorCount = activatorCount -1;
		if (isTriggered) {
			Trigger(false);
		}
	}
}


