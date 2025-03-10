// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AMyAIController();

	// Controller�� Pawn�� ���ǵ� �� ȣ��Ǵ� �Լ�
	virtual void OnPossess(APawn* InPawn) override;

	// Controller�� Pawn�� ���ǰ� ������ �� ȣ��Ǵ� �Լ�
	virtual void OnUnPossess() override;
	
	UFUNCTION()
	void RandMove();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBlackboardData* _blackBoard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBehaviorTree* _behaviorTree;

private:
	UPROPERTY()
	FTimerHandle _timerHandle;

};
