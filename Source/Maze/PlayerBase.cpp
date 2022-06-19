// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	initialLife = life;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	initialPosition = GetActorLocation();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (life<=0) {

		life = initialLife;
		SetActorLocation(initialPosition);
		respawns--;
		if (respawns<0)
		{
			Destroy();
		}
	}

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Forward", this, &APlayerBase::ForwardAxis);
	InputComponent->BindAxis("Side", this, &APlayerBase::SideAxis);

}

void APlayerBase::ForwardAxis(float axis)
{
	FVector movement(0, 0, 0);
	movement.X = axis * velocity * GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(movement, true);
}

void APlayerBase::SideAxis(float axis)
{
	FRotator rotation(0, 0, 0);
	rotation.Yaw = axis * rotationVelocity * GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(rotation, true);
}

