// Fill out your copyright notice in the Description page of Project Settings.


#include "WallTrap.h"

// Sets default values
AWallTrap::AWallTrap()
{
	//PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWallTrap::BeginPlay()
{
	GetWorldTimerManager().SetTimer(timerHToShoot, this, &AWallTrap::ShootObject, timeToShoot, true);

}

//void AWallTrap::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AWallTrap::ShootObject()
{
	FVector posicion1 = GetActorLocation();
	FRotator rotacion1 = GetActorRotation();

	GetWorld()->SpawnActor<AActor>(objectToShoot, posicion1, rotacion1);

}


