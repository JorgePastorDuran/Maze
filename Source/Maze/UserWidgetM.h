// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetM.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API UUserWidgetM : public UUserWidget
{
	GENERATED_BODY()

	class AMazeGameModeBase* gameMode;

	class APlayerBase* playerBase;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* scoreLabel;	

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* lifeBar;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* NumberLifes;
	

	void NativeConstruct() override;
	void NativeTick(const FGeometry& geometry, float deltaTime) override;

	
};
