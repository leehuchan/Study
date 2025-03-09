// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyItem.h"
#include "MyInvenComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FItemAdd, int32, FMyItemInfo)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALSTUDY_API UMyInvenComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyInvenComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem(int32 itemID, MyItemType type);
	FMyItemInfo DropItem();
	FMyItemInfo DropItem(int32 index);

	FItemAdd itemAddEvent;
private:
	// TODO : itemComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowPrivateAccess = "true"))
	TArray<FMyItemInfo> _items;
};
