// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	// ��� �޾����� ������ �ؾ���
	Super::OnPossess(InPawn);

	// 3�ʸ��� RandMove�Լ� �ݺ������� ȣ��
	// GetWorld()->GetTimerManager().SetTimer(_timerHandle, this, &AMyAIController::RandMove, 3.0f, true);

	UBlackboardComponent* temp = Blackboard;

	if (UseBlackboard(_blackBoard, temp))
	{
		if (RunBehaviorTree(_behaviorTree))
		{

		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("BT Failed"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BB Failed"));
	}
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	// GetWorld()->GetTimerManager().ClearTimer(_timerHandle);
}

void AMyAIController::RandMove()
{
	auto curPawn = GetPawn(); // ���� ���ǵǾ��ִ� ��

	if (curPawn->IsValidLowLevel() == false)
		return;

	// ���� ������ NavMesh�� ���� ���� ��
	auto navMesh = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (navMesh->IsValidLowLevel() == false)
		return;

	// ������ ��ġ => navMesh �����
	FNavLocation randLocation;

	if (navMesh->GetRandomPointInNavigableRadius(FVector::ZeroVector, 5.0f, randLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, randLocation.Location);
	}
}
