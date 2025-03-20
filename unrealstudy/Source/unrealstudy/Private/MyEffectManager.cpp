// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffectManager.h"

#include "NiagaraSystem.h"
#include "Particles/ParticleSystem.h"

// Sets default values
AMyEffectManager::AMyEffectManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	CreateEffect(TEXT("BigFire"), TEXT("/Script/Niagara.NiagaraSystem'/Game/Graphics/Effect/Vefects/Free_Fire/Shared/Particles/NS_Fire_Big_Simple.NS_Fire_Big_Simple'"));
	CreateEffect(TEXT("MeleeAttack"), TEXT("/Script/Engine.ParticleSystem'/Game/ParagonSunWukong/FX/Particles/Wukong/Abilities/Primary/FX/P_Wukong_Impact.P_Wukong_Impact'"));
}

// Called when the game starts or when spawned
void AMyEffectManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Ǯ��
	for (auto particle : _particleTable)
	{
		FString name = particle.Key;
		_effectTable.Add(name);

		for (int i = 0; i < 5; i++)
		{
			auto effect = GetWorld()->SpawnActor<AMyEffect>(FVector::ZeroVector, FRotator::ZeroRotator);
			effect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			auto niagara = Cast<UNiagaraSystem>(_particleTable[name]);
			if (niagara)
			{
				effect->SetParticle(niagara);
			}
			else
			{
				effect->SetParticle(Cast<UParticleSystem>(_particleTable[name]));
			}
			effect->Stop();

			_effectTable[name]._effects.Add(effect);
		}
	}
}

// Called every frame
void AMyEffectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffectManager::PlayEffect(FString key, FVector pos)
{
	auto effects = _effectTable.Find(key);

	if (effects == nullptr)
	{
		return;
	}

	// ����Ʈ �����ִ� �� ã��
	auto iter = effects->_effects.FindByPredicate([](AMyEffect* effect)->bool
		{
			if (!effect->IsActive())
				return true;
			return false;
		});

	// ����Ʈ �����ִ� ���� ����
	if (iter)
	{
		(*iter)->Play(pos);
	}
}

void AMyEffectManager::CreateEffect(FString key, FString path)
{
	ConstructorHelpers::FObjectFinder<UFXSystemAsset> particle(*path);

	if (particle.Succeeded())
	{
		_particleTable.Add(key, particle.Object);
	}

}

