// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h" // 무조건 맨 마지막에 헤더파일이 있어야 함 그렇지 않을 경우 문제가 생김

UENUM()
enum class MyItemType
{
	NONE,
	POTION
};


USTRUCT(BlueprintType)
struct FMyItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemId = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	MyItemType type = MyItemType::NONE;
};

UCLASS()
class UNREALSTUDY_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	virtual void PostInitializeComponents()override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(class UPrimitiveComponent* overlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormWeep, const struct FHitResult& SweepResult);

	const FMyItemInfo& GetInfo() { return _info; }

private:
	UPROPERTY(EditAnywhere , Category = "Mesh")
	UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "Collider")
	class UCapsuleComponent* _collider;

	UPROPERTY(EditAnywhere, Category = "ItemInfo")
	FMyItemInfo _info;
};
