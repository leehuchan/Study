// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_Service_FindTarget.h"

#include "MyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"

#include "DrawDebugHelpers.h"
#include "Engine/OverlapResult.h"

#include "MyPlayer.h"

void UBT_Service_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// ���� ���ǵ� Pawn ã��
	auto currentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (currentPawn->IsValidLowLevel() == false)
		return;

	FVector pos = currentPawn->GetActorLocation();
	float sphereRadius = 500.0f;

	TArray<FOverlapResult> overlapResults;
	FCollisionQueryParams qParams(NAME_None, false, currentPawn);

	bool result = GetWorld()->OverlapMultiByChannel(
		overlapResults,
		pos,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(sphereRadius),
		qParams
	);

	if (!result)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Player")), nullptr);
		DrawDebugSphere(GetWorld(), pos, sphereRadius, 30, FColor::Green, false, 0.3f);

		return;
	}
	else
	{
		for (auto& overlapResult : overlapResults)
		{
			auto player = Cast<AMyPlayer>(overlapResult.GetActor());

			if (player->IsValidLowLevel())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Player")), player);
				DrawDebugSphere(GetWorld(), pos, sphereRadius, 30, FColor::Red, false, 0.3f);

				FRotator rot = (player->GetActorLocation() - currentPawn->GetActorLocation()).GetSafeNormal().Rotation();
				currentPawn->SetActorRotation(FMath::RInterpTo(currentPawn->GetActorRotation(), rot, DeltaSeconds, 0.5f));

				return;
			}
		}
	}
}
