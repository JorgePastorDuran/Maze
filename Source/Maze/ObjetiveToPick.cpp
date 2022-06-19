// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjetiveToPick.h"
#include "PlayerBase.h"
#include "MazeGameModeBase.h"



// Sets default values
AObjetiveToPick::AObjetiveToPick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjetiveToPick::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AObjetiveToPick::OnOverlap);
	
}

// Called every frame
//void AObjetiveToPick::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AObjetiveToPick::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);
	if (pb != nullptr )
	{
		AGameModeBase* gameModeBase = GetWorld()->GetAuthGameMode();
		AMazeGameModeBase* gameMode = Cast<AMazeGameModeBase>(gameModeBase);
		if (gameMode != nullptr)
		{
			gameMode->pickedObjetives++;
			Destroy();
		}
	}
}

