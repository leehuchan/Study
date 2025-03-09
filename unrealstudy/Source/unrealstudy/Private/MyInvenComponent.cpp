// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInvenComponent.h"

#include "MyItem.h"

// Sets default values for this component's properties
UMyInvenComponent::UMyInvenComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	_items.SetNum(9);
}


// Called when the game starts
void UMyInvenComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyInvenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FMyItemInfo UMyInvenComponent::GetItemInfo_Index(int32 index)
{
    if (index < 0 || index >= _items.Num())
        return FMyItemInfo();

    if (_items[index] == nullptr)
        return FMyItemInfo();

    return _items[index]->GetInfo();
}

void UMyInvenComponent::AddItem(AMyItem* item)
{
	auto target = _items.FindByPredicate([](AMyItem* item)-> bool
		{
			if (item == nullptr)
				return true;
			return false;
		});

	// ��ĭ�� ����
	if (target == nullptr)
		return;

	*target = item;
	// TODO : InventoryUI
	int32 targetIndex = 0;

	int64 temp1 = (int64)target;
	int64 temp2 = (int64)(&_items[0]);
	targetIndex = (temp1 - temp2) / sizeof(int64);

	itemAddEvent.Broadcast(targetIndex, item->GetInfo());
}

AMyItem* UMyInvenComponent::DropItem()
{
	return nullptr;
}

AMyItem* UMyInvenComponent::DropItem(int32 index)
{
	if (index >= _items.Num() || index < 0)
		return nullptr;

	if (_items[index] == nullptr)
		return nullptr;

	AMyItem* dropItem = _items[index];
	_items[index] = nullptr;
	// TODO : ���� �������� �ٴڿ� ��������
	// 1. GetOwner() -> Player
	// => Cast<MyPlayer> 
	// => MyPlayer�� Drop�Լ��� ȣ��
	// player->DropItem(dropItem);

	// 2. ItemDropEvent�� ����
	// => MyPlayer�� Drop�Լ��� ���ε��ؼ� ����ȣ��

	return dropItem;
}

