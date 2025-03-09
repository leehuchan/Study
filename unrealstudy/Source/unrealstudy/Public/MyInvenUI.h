// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyItem.h"
#include "MyInvenUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSTUDY_API UMyInvenUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual bool Initialize() override;

    void SetItem_Index(int32 index, FMyItemInfo info);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    class UUniformGridPanel* Grid;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    class UButton* Drop;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<class UImage*> _slotImages;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<class UButton*> _slotButtons;

    // #TODO
    UPROPERTY()
    UTexture2D* _defaultTexture;
    UPROPERTY()
    UTexture2D* _potionTexture;

    int32 _curIndex = -1;
};
