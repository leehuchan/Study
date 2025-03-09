// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* subSystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (subSystem)
	{
		subSystem->AddMappingContext(_inputMappingContext, 0);
	}
}

void AMyPlayerController::ShowUI()
{
	// ���콺 Ŀ��
	bShowMouseCursor = true;
}

void AMyPlayerController::HideUI()
{
	// ���콺 Ŀ��
	bShowMouseCursor = false;
}
