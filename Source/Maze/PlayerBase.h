// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBase.generated.h"

UCLASS()
class MAZE_API APlayerBase : public APawn
{
	GENERATED_BODY()

public:

	APlayerBase();

protected:

	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere) 
		float velocity;
	UPROPERTY(EditAnywhere) 
		float rotationVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float life;
	UPROPERTY(EditAnywhere)
		int respawns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float initialLife;
	UPROPERTY(VisibleAnywhere)
		class ACheckPoint* currentCheckpoint;

	int keys;
	FVector initialPosition;

	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void ForwardAxis(float axis);
	void SideAxis(float axis);


};
