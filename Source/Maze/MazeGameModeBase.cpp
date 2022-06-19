// Copyright Epic Games, Inc. All Rights Reserved.


#include "MazeGameModeBase.h"



AMazeGameModeBase::AMazeGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMazeGameModeBase::Tick(float deltaSecons)
{
	if (pickedObjetives >= objectivesToPick)
	{
		GetWorld()->ServerTravel("win");
	}

}
