// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREALSTUDY_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const struct FInputActionValue& value);
	UFUNCTION()
	void Look(const struct FInputActionValue& value);
	UFUNCTION()
	void JumpA(const struct FInputActionValue& value);
	UFUNCTION()
	void Attack(const struct FInputActionValue& value);

	UFUNCTION()
	void TestDelegate();

	UFUNCTION()
	int32 TestDelegate2(int32 a, int32 b);

	UFUNCTION()
	void AttackEnd(class UAnimMontage* Montage, bool BInterrupted);

	float My_Vertical() { return _vertical; }
	float My_Horizontal() { return _horizontal; }

	bool CanJump() const;


private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _lookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _jumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* _attackAction;

	// �𸮾��� �ٽɱ���
	// 1. ���
	// 2. ������Ʈ
	//
	// ������Ʈ ���� : ��ǰ
	// 1. Actor ������Ʈ
	// 2. Scene ������Ʈ

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	float _speed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	float _jumpVelocity = 500.f;

	// Attack �׼��� ȣ��Ǹ� isAttack�� true
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool _isAttack;

	UPROPERTY()
	class UMyAnimInstance* _animInstance;

	int32 _curAttackSection = 1;

	float _vertical = 0.0f;
	float _horizontal = 0.0f;

};
