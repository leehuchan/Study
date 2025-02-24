// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyTutoPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	// BluePrint Class Type�� ������ �� _C�� �������Ѵ�.
	static ConstructorHelpers::FClassFinder<AMyTutoPawn> pawn
	(TEXT("/Script/Engine.Blueprint'/Game/BluePrints/BP_MyCharacter.BP_MyCharacter_C'"));

	if (pawn.Succeeded())
	{
		DefaultPawnClass = pawn.Class;
	}
}
