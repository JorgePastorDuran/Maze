// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VerticalTrap.generated.h"

UCLASS()
class MAZE_API AVerticalTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVerticalTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle timerHandleTrap;
	void changeDirection();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);

	UPROPERTY(EditAnywhere) 
		float velocity;	
	UPROPERTY(EditAnywhere) 
		float changeTime;
	UPROPERTY(EditAnywhere)
		float damage;

};
