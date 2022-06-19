// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "PlayerBase.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(velocityShoot, true);

}

void ABullet::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast <APlayerBase>(other);
	if (pb != nullptr) {

		pb->life -= damage;
		
	}
	Destroy();

}
