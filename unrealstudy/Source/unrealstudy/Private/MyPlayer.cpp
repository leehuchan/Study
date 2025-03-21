// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "MyPlayerController.h"
#include "MyStatComponent.h"
#include "MyAnimInstance.h"
#include "MyItem.h"

#include "Blueprint/UserWidget.h"
#include "MyInvenUI.h"
#include "Components/Button.h"
#include "MyInvenComponent.h"

#include "MyProjectile.h"

#include "MyGameInstance.h"
#include "Engine/DamageEvents.h"

AMyPlayer::AMyPlayer()
{
    PrimaryActorTick.bCanEverTick = true;

    _springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    _camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

    // ��Ӱ��� ����
    _springArm->SetupAttachment(GetCapsuleComponent());
    _camera->SetupAttachment(_springArm);

    _springArm->TargetArmLength = 500.0f;
    _springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

    // Inventory
    static ConstructorHelpers::FClassFinder<UMyInvenUI> invenClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/BP_MyInven.BP_MyInven_C'"));
    if (invenClass.Succeeded())
    {
        _invenWidget = CreateWidget<UUserWidget>(GetWorld(), invenClass.Class);
    }

    _invenComponent = CreateDefaultSubobject<UMyInvenComponent>(TEXT("InvenComponent"));
}

void AMyPlayer::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    auto invenUI = Cast<UMyInvenUI>(_invenWidget);
    if (invenUI)
    {
        invenUI->_invenComponent = _invenComponent;
        _invenComponent->itemAddEvent.AddUObject(invenUI, &UMyInvenUI::SetItem_Index);
        invenUI->Drop->OnClicked.AddDynamic(this, &AMyPlayer::Drop);
    }
}

void AMyPlayer::BeginPlay()
{
    Super::BeginPlay();
}

void AMyPlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* enhancedInputCompnent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (enhancedInputCompnent)
    {
        enhancedInputCompnent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPlayer::Move);
        enhancedInputCompnent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyPlayer::Look);
        enhancedInputCompnent->BindAction(_jumpAction, ETriggerEvent::Triggered, this, &AMyPlayer::JumpA);
        enhancedInputCompnent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &AMyPlayer::Attack);
        enhancedInputCompnent->BindAction(_dropAction, ETriggerEvent::Started, this, &AMyPlayer::DropA); // Ű���� XŰ
        enhancedInputCompnent->BindAction(_invenAction, ETriggerEvent::Started, this, &AMyPlayer::InvenOpen);

    }
}

void AMyPlayer::Move(const FInputActionValue& value)
{
    if (_isAttack) return;

    FVector2D moveVector = value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        if (moveVector.Length() > 0.01f)
        {
            FVector forWard = GetActorForwardVector();
            FVector right = GetActorRightVector();

            _vertical = moveVector.Y;
            _horizontal = moveVector.X;

            AddMovementInput(forWard, moveVector.Y * _statComponent->GetSpeed());
            AddMovementInput(right, moveVector.X * _statComponent->GetSpeed());
        }
    }
}

void AMyPlayer::Look(const FInputActionValue& value)
{
    FVector2D lookAxisVector = value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        AddControllerYawInput(lookAxisVector.X);
        AddControllerPitchInput(-lookAxisVector.Y);
    }
}

void AMyPlayer::JumpA(const FInputActionValue& value)
{
    if (_isAttack) return;

    bool isPress = value.Get<bool>();

    if (isPress)
    {
        ACharacter::Jump();
    }
}

void AMyPlayer::Attack(const FInputActionValue& value)
{
    if (_isAttack) return;

    bool isPress = value.Get<bool>();

    if (isPress)
    {
        _isAttack = true;

        _curAttackSection = (_curAttackSection % 5) + 1;
		_animInstance->PlayAnimMontage();

		_animInstance->JumpToSection(_curAttackSection);

        // ����ü
        if (_curAttackSection == 5)
        {
            FVector startPos = GetMesh()->GetSocketLocation(TEXT("s_throw"));
            FVector direction = _camera->GetForwardVector();

            auto projectile = GetWorld()->SpawnActor<AMyProjectile>(_projectileClass, startPos, FRotator::ZeroRotator);

            projectile->SetOwner(this);
            projectile->FireDirection(direction);
        }
        
    }
}

void AMyPlayer::DropA(const FInputActionValue& value)
{
    if (_isAttack)
        return;

    bool isPress = value.Get<bool>();

    Drop();
}

void AMyPlayer::InvenOpen(const FInputActionValue& value)
{
    bool isPress = value.Get<bool>();

    if (isPress)
    {
        auto controller = Cast<AMyPlayerController>(GetController());
        if (_isInvenOpen)
        {
            if (controller)
                controller->HideUI();
            _invenWidget->RemoveFromViewport();
        }
        else
        {
            if (controller)
                controller->ShowUI();
            _invenWidget->AddToViewport();
        }
        _isInvenOpen = !_isInvenOpen;
    }
}

void AMyPlayer::Attack_Hit()
{
    if (IsDead())
        return;

    FHitResult hitResult;
    FCollisionQueryParams params(NAME_None, false, this);

    float attackRadius = 70.0f;

    FVector forward = _camera->GetForwardVector();
    FQuat quat = FQuat::FindBetweenVectors(FVector(0, 0, 1), forward);

    FVector center = GetActorLocation() + forward * _attackRange * 0.5f;
    FVector start = GetActorLocation() + forward * _attackRange * 0.5f;
    FVector end = GetActorLocation() + forward * _attackRange * 0.5f;

    //Sweep : start���� end���� ������ ������ �浹 ����
    bool bResult = GetWorld()->SweepSingleByChannel
    (
        OUT hitResult,
        start,
        end,
        quat, // ȸ�� ��Ű��
        ECC_GameTraceChannel2,
        FCollisionShape::MakeCapsule(attackRadius, _attackRange * 0.5f),
        params
    );

    FColor drawColor = FColor::Green;

    if (bResult && hitResult.GetActor()->IsValidLowLevel())
    {
        drawColor = FColor::Red;
        AMyCharacter* victim = Cast<AMyCharacter>(hitResult.GetActor());

        if (victim)
        {
            FDamageEvent damageEvent = FDamageEvent();

            FVector hitPoint = hitResult.ImpactPoint;
            EFFECT_M->PlayEffect("MeleeAttack", hitPoint);

            victim->TakeDamage(_statComponent->GetAtk(), damageEvent, GetController(), this);
        }

    }

    // �浹ü �׸���
    DrawDebugCapsule(GetWorld(), center, _attackRange * 0.5f, attackRadius, quat, drawColor, false, 1.0f);
}

void AMyPlayer::AddItem(AMyItem* item)
{
    // TODO
    if (item && _invenComponent)
    {
        _invenComponent->AddItem(item);

    }
}

void AMyPlayer::Drop()
{
    UE_LOG(LogTemp, Error, TEXT("Drop"));

    int32 curDropIndex = -1;
    auto invenUI = Cast<UMyInvenUI>(_invenWidget);

    if (invenUI)
        curDropIndex = invenUI->_curIndex;

    auto item = _invenComponent->DropItem(curDropIndex);

    if (item == nullptr)
        return;

    invenUI->SetItem_Index(curDropIndex, FMyItemInfo());

    FVector playerLocation = GetActorLocation();

    float dropRadius = 200.0f;
    FVector randomOffset = FMath::VRand() * FMath::FRandRange(100.0f, dropRadius);
    FVector dropLocation = playerLocation + randomOffset;
    dropLocation.Z = 40.0f;

    item->SetActorLocation(dropLocation);
    item->SetActorHiddenInGame(false);
    item->SetActorEnableCollision(true);
}
