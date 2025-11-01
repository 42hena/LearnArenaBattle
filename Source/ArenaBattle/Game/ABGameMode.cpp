// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"

#include "Player/ABPlayerController.h"

#pragma region 특수맴버함수

AABGameMode::AABGameMode()
{
	// DefaultPawnClass 지정
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/CoreUObject.Class'/Script/ArenaBattle.ABCharacterPlayer'"));
	ensureAlways(DefaultPawnClassRef.Class);
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	// PlayerController 지정
	// 방법 1: StaticClass 이용 - 헤더 필수
	PlayerControllerClass = AABPlayerController::StaticClass();

	// 방법 2: ConstructorHelpers::FClassFinder 이용. - 에셋으로부터 직접 참조, 헤더 파일 의존성 제거
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/CoreUObject.Class'/Script/ArenaBattle.ABPlayerController'"));
	ensureAlways(PlayerControllerClassRef.Class);
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
}

#pragma endregion
