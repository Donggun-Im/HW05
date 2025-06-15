// Fill out your copyright notice in the Description page of Project Settings.
#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	moveCount = 10;
	position = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < moveCount; ++i)
	{
		move();
		int event = createEvent();
		if (event >0)
		{
			UE_LOG(LogTemp, Log,  TEXT("Event %d happened"),event);
		}

	}
	float distance = Distance(position , {0,0,0});
	UE_LOG(LogTemp, Log, TEXT("Move distance: %f"), distance);
	
}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AMyActor::Distance(FVector first, FVector second)
{
	float result = 0;
	result = FMath::Sqrt((first.X-second.X)*(first.X - second.X) + (first.Y - second.Y)*(first.Y - second.Y));
	return result;
}

int32_t AMyActor::step()
{
	
	return FMath::RandRange(0, 1);
}

void AMyActor::move()
{
	int moveX = step();
	int moveY = step();
	
	
	position.X += moveX;
	position.Y += moveY;
	//FString strd = FString::Printf(TEXT("MyActor moves (%d, %d)"),moveX, moveY);
	//FString strd2 = FString::Printf(TEXT("Current Position (%.1f, %.1f)"), FString::SanitizeFloat(position.X), FString::SanitizeFloat(position.Y));

	UE_LOG(LogTemp, Log, TEXT("MyActor moves (%d, %d)"), moveX, moveY);
	UE_LOG(LogTemp, Log, TEXT("Current Position (%.1f, %.1f)"), position.X, position.Y);
	//UE_LOG(LogTemp, Log, TEXT("%s"), *strd);
	//UE_LOG(LogTemp, Log, TEXT("%s"), *strd2);

}

int32 AMyActor::createEvent()
{
	int event = FMath::RandRange(0, 10);
	if ( event < 3)
	{
		return event+1;
	}
	return 0;
}

