// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"

UMyAnimInstance::UMyAnimInstance()
{
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	auto pawn = TryGetPawnOwner();
	AMyCharacter* character = Cast<AMyCharacter>(pawn); // dynamicCast

	if (character != nullptr)
	{
		_speed = character->GetVelocity().Size();
		_isFalling = character->GetMovementComponent()->IsFalling();
		_vertical = character->My_Vertical();
		_horizontal = character->My_Horizontal();
		_isDead = character->IsDead();
		_isAttacking = character->IsAttacking();
	}
}

void UMyAnimInstance::PlayAnimMontage()
{
	if (_animMontage == nullptr)
		return;

	if (!Montage_IsPlaying(_animMontage))
	{
		// Attack Delegate ����
		//_attackStart.Execute();
		//_attackStart2.Execute(1, 2);
		//_attackStart3.Broadcast(); // ��Ƽĳ��Ʈ

		Montage_Play(_animMontage);
	}
}

void UMyAnimInstance::AnimNotify_Attack_Hit()
{
	// ���� ���� �ִ� ĳ������ AttackHit
	if (_hitEvent.IsBound())
		_hitEvent.Broadcast();
}

void UMyAnimInstance::AnimNotify_Dead()
{
	// �׾��� �� ������ �̺�Ʈ��
	if (_deadEvent.IsBound())
		_deadEvent.Broadcast();
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	// Section1, Section2, Section3, Section4, Section5
	FName sectionName = FName(*FString::Printf(TEXT("Section%d"), sectionIndex));
	Montage_JumpToSection(sectionName, _animMontage);
}
