// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/ABAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#pragma region 특수맴버함수

UABAnimInstance::UABAnimInstance()
{
	MovingThreshold = 3.0f;
	JumpingThreshold = 100.0f;
}

#pragma endregion

#pragma region 엔진제공함수

void UABAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// 굳이 필요하진 않음. 자주 쓰니까 그런거임.
	Owner = Cast<ACharacter>(GetOwningActor());
	if (Owner != nullptr)
	{
		Movement = Owner->GetCharacterMovement();
	}
}

void UABAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Movement != nullptr)
	{
		Velocity = Movement->Velocity;
		GroundSpeed = Velocity.Size2D();
		bIsIdle = GroundSpeed < MovingThreshold;
		bIsFalling = Movement->IsFalling();
		bIsJumping = bIsFalling & (Velocity.Z > JumpingThreshold);
	}
}

#pragma endregion
