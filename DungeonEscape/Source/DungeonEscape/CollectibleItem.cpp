// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleItem.h"

// Sets default values
ACollectibleItem::ACollectibleItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("CollectibleItem");

}
void callByRef(FVector& cbRef) {

	cbRef.X = 20.0f;
	cbRef.Y = 20.0f;
	cbRef.Z = 20.0f;
}

// Called when the game starts or when spawned
void ACollectibleItem::BeginPlay()
{
	Super::BeginPlay();

	FVector emo = FVector(1.0, 1.0, 1.0);
	FVector& emoRef = emo;

	UE_LOG(LogTemp, Display, TEXT("Emo values are: %s"), *emo.ToCompactString());
	UE_LOG(LogTemp, Display, TEXT("EmoRef Values are: %s"), *emoRef.ToCompactString());

	emoRef.X = 5.0f;
	emoRef.Y = 5.0f;
	emoRef.Z = 5.0f;

	UE_LOG(LogTemp, Display, TEXT("Emo values are: %s"), *emo.ToCompactString());
	UE_LOG(LogTemp, Display, TEXT("EmoRef Values are: %s"), *emoRef.ToCompactString());


	FVector cbRef = FVector(3.0f, 3.0f, 3.0f);
	UE_LOG(LogTemp, Display, TEXT("cbRef before the function: %s"), *cbRef.ToCompactString());

	callByRef(cbRef);
	UE_LOG(LogTemp, Display, TEXT("cbRef after the function: %s"), *cbRef.ToCompactString());


}




// Called every frame
void ACollectibleItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



//	UE_LOG(LogTemp, Display, TEXT("Time is: %f "), GetWorld()->TimeSeconds);

}

