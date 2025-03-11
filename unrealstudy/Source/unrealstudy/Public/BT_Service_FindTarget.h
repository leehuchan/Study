// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BT_Service_FindTarget.generated.h"

/*
BT_Service
�ֱ������� üũ
=> �ֱ������� Player�� ���Ϳ� ������ �ִ��� üũ�ϰ� BlackBoard�� ����
 */
UCLASS()
class UNREALSTUDY_API UBT_Service_FindTarget : public UBTService
{
	GENERATED_BODY()
	
public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
