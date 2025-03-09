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

	//UFUNCTION() // 충돌되었을 때 호출되는 함수 / AActor* OtherActor 캐스팅해서 캐릭터 확인 해보자
	//void OnMyCharacterOverlap(UPrimitiveComponent* overlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormWeep, const FHitResult& SweepResult);

	UFUNCTION()
	void TestDelegate();

	UFUNCTION()
	int32 TestDelegate2(int32 a, int32 b);

	UFUNCTION()
	void AttackEnd(class UAnimMontage* Montage, bool BInterrupted);

	float My_Vertical() { return _vertical; }
	float My_Horizontal() { return _horizontal; }

	// bool CanJump() const;

	void Attack_Hit();
	void DeadEvent();

	void AddHp(float amount);

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	bool IsDead();

protected:
	// 언리얼의 핵심구조
	// 1. 상속
	// 2. 컴포넌트
	//
	// 컴포넌트 패턴 : 부품
	// 1. Actor 컴포넌트
	// 2. Scene 컴포넌트

	UPROPERTY()
	class UMyAnimInstance* _animInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	class UMyStatComponent* _statComponent;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat", meta = (AllowPrivateAccess = "true"))
	//float _jumpVelocity = 500.f;

	// Attack 액션이 호출되면 isAttack을 true
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	bool _isAttack;

	int32 _curAttackSection = 1;

	float _vertical = 0.0f;
	float _horizontal = 0.0f;

};
