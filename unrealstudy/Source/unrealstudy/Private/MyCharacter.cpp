// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "MyAnimInstance.h"

#include "Engine/DamageEvents.h"

#include "MyStatComponent.h"
#include "Components/WidgetComponent.h"
#include "MyPlayerController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// bluePrint���� SkeletalMesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	_statComponent = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (_animInstance == nullptr)
		UE_LOG(LogTemp, Error ,TEXT("AnimInstance did not Set"));

	// Delegate ���ε� ����
	_animInstance->_attackStart.BindUObject(this, &AMyCharacter::TestDelegate);
	_animInstance->_attackStart2.BindUObject(this, &AMyCharacter::TestDelegate2);
	_animInstance->_attackStart3.AddDynamic(this, &AMyCharacter::TestDelegate);
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::AttackEnd);
	_animInstance->_hitEvent.AddUObject(this, &AMyCharacter::Attack_Hit);
	_animInstance->_deadEvent.AddUObject(this, &AMyCharacter::DeadEvent);

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyCharacter::TestDelegate()
{
	UE_LOG(LogTemp, Log, TEXT("Attack Start Delegate Test"));
}

int32 AMyCharacter::TestDelegate2(int32 a, int32 b)
{
	UE_LOG(LogTemp, Log, TEXT("Attack Start Delegate Test, %d, %d"), a, b);

	return -1;
}

void AMyCharacter::AttackEnd(UAnimMontage* Montage, bool BInterrupted)
{
	_isAttack = false;
}

void AMyCharacter::Attack_Hit()
{
	if (IsDead())
		return;

	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	float attackRadius = 70.0f;

	// ĸ��
	// 1. ȸ��
	// 2. ĸ���� Radius, halfHeight
	// 3. �浹ó���� DebugDraw

	FVector forward = GetActorForwardVector();
	FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);

	FVector center = GetActorLocation() + forward * _attackRange * 0.5f;
	FVector start = GetActorLocation() + forward * _attackRange * 0.5f;
	FVector end = GetActorLocation() + forward * _attackRange * 0.5f;

	//Sweep : start���� end���� ������ ������ �浹 ����
	bool bResult = GetWorld()->SweepSingleByChannel
	(
		OUT hitResult,
		start,
		end,
		quat, // ȸ�� ��Ű��
		ECC_GameTraceChannel2,
		FCollisionShape::MakeCapsule(attackRadius, _attackRange * 0.5f),
		params
	);

	FColor drawColor = FColor::Green;

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		drawColor = FColor::Red;
		AMyCharacter* victim = Cast<AMyCharacter>(hitResult.GetActor());

		if (victim)
		{
			FDamageEvent damageEvent = FDamageEvent();

			victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
		}

	}

	// �浹ü �׸���
	DrawDebugCapsule(GetWorld(), center, _attackRange * 0.5f, attackRadius, quat, drawColor, false, 1.0f);
}

void AMyCharacter::DeadEvent()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	Controller->UnPossess();
}

void AMyCharacter::AddHp(float amount)
{
	_statComponent->AddCurHp(amount);
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	_statComponent->AddCurHp(-DamageAmount);

	auto attackerController = Cast<AMyPlayerController>(EventInstigator);
	if (attackerController)
	{
		// Player...
		if (IsDead())
		{
			UE_LOG(LogTemp, Error, TEXT("Be Dead by Player"));
		}
	}

	return DamageAmount;
}

bool AMyCharacter::IsDead()
{
	return _statComponent->IsDead();
}
