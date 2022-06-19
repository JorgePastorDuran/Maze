// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()


	UPROPERTY(meta = (BindWidget))
		class UButton* playBtn;

	UPROPERTY(meta = (BindWidget))
		class UButton* ExitBtn;

	void NativeConstruct() override;

	UFUNCTION()
		void Play();

	UFUNCTION()
		void Exit();
	
};
