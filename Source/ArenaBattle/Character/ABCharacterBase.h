// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Interface/ABAnimationAttackInterface.h"

#include "ABCharacterBase.generated.h"

UENUM()
enum class ECharacterControlType : uint8
{
	Shoulder,
	Quarter
};

UCLASS()
class ARENABATTLE_API AABCharacterBase : public ACharacter,
	public IABAnimationAttackInterface
{
	GENERATED_BODY()

#pragma region 특수맴버함수
public:
	AABCharacterBase();
#pragma endregion

#pragma region 엔진제공함수
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
#pragma endregion

#pragma region 가상함수
protected:
	// DataAsset변경가상함수
	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData);

	// 죽는 함수
	virtual void SetDead();
	void PlayDeadAnimation();
#pragma endregion

#pragma region ComboAction함수
	void ProcessComboCommand();

	void ComboActionBegin();
	void ComboActionEnd(class UAnimMontage* TatgetMontage, bool bInterrupted);

	void SetComboCheckTimer();
	void ComboCheck();
#pragma endregion

#pragma region AttackHitSection함수
	virtual void AttackHitCheck() override;
#pragma endregion

	UPROPERTY(EditAnywhere, Category = CharacterControl, Meta = (AllowPrivateAccess = "true"))
	TMap<ECharacterControlType, class UABCharacterControlData *> CharacterControlManager;
	//TMap<ECharacterControlType, TObjectPtr<class UABCharacterControlData>> CharacterControlManager;

#pragma region ComboAction변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> ComboActionMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UABComboActionData> ComboActionData;

	int32 CurrentCombo = 0;

	FTimerHandle ComboTimerHandle;
	bool HasNextComboCommand = false;
#pragma endregion

#pragma region Dead변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAnimMontage> DeadMontage;

	float DeadEventDelayTime = 5.0f;
#pragma endregion

};
