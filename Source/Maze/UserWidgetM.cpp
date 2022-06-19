// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetM.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "MazeGameModeBase.h"
#include "PlayerBase.h"



void UUserWidgetM::NativeConstruct()
{
	Super::NativeConstruct();

	AGameModeBase* mode = GetWorld()->GetAuthGameMode();
	APawn* pawn = GetWorld()->GetFirstPlayerController()->GetPawn();

		if (mode != nullptr && pawn != nullptr)
		{
			gameMode = Cast<AMazeGameModeBase>(mode);
			playerBase = Cast<APlayerBase>(pawn);
		}
					
}

void UUserWidgetM::NativeTick(const FGeometry& geometry, float deltaTime)
{
	Super::NativeTick(geometry, deltaTime);

	FString pickedObj = FString::FromInt(gameMode->pickedObjetives); 
	FText TextpickedObjetives = FText::FromString(pickedObj);
	scoreLabel->SetText(TextpickedObjetives);

	float percent = playerBase->life / playerBase->initialLife;
	lifeBar->SetPercent(percent);

	FString Lifes = FString::FromInt(playerBase->respawns); 
	FText TextLifes = FText::FromString(Lifes);
	NumberLifes->SetText(TextLifes);

}



