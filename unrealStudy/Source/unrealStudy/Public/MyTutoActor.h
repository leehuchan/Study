// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTutoActor.generated.h"

// 1. �޸�
// 2. ���÷���(reflection)

UCLASS() // UObject�� ��ӹ޴� Ŭ����
class UNREALSTUDY_API AMyTutoActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTutoActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// actor�� ���忡�� �����ҷ��� transform
	// ���� ���Ϸ���, ���� ĥ�ҷ���
	// 1. mesh�� �־���Ѵ�.
	// 2. material�� �־���Ѵ�.
	// 3. transform(4x4���)

};
