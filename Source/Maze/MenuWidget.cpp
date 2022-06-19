// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"
#include "Components/Button.h"



	void UMenuWidget::NativeConstruct()
	{
		playBtn->OnClicked.AddDynamic(this, &UMenuWidget::Play);
		ExitBtn->OnClicked.AddDynamic(this, &UMenuWidget::Exit);


	}

	void UMenuWidget::Play()
	{
		GetWorld()->ServerTravel("MazeMap");
	}

	void UMenuWidget::Exit()
	{
		FGenericPlatformMisc::RequestExit(false);

	}
