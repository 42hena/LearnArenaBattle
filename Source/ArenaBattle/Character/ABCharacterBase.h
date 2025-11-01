// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quarter
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter
{
	GENERATED_BODY()

#pragma region 특수맴버함수
public:
	AABCharacterBase();
#pragma endregion

#pragma region 가상함수
protected:
	// DataAsset변경가상함수
	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);
#pragma endregion

	UPROPERTY(EditAnywhere, Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterControlType, class UABCharacterControlData *> CharacterControlManager;
	//TMap<ECharacterControlType, TObjectPtr<class UABCharacterControlData>> CharacterControlManager;
};
