// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ABPlayerController.h"

#pragma region 엔진제공함수

void AABPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 게임 시작 시 마우스 입력이 자동으로 들어가도록 설정. -> 왜 PlayerController에서 하지?
	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}

#pragma endregion