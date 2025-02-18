#include "framework.h"
#include "ArkItem.h"

ArkItem::ArkItem()
{
	_body = make_shared < CircleCollider(_pos, 5.0f);
}

ArkItem::~ArkItem()
{
}

void ArkItem::Update()
{
}

void ArkItem::Render(HDC hdc)
{
}
