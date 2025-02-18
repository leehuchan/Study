#include "framework.h"
#include "ArkBlock.h"

ArkBlock::ArkBlock()
:RectCollider(Vector(0, 0), Vector(150, 20))
{
	_brushes.push_back(CreateSolidBrush(BLACK)); // NONE
	_brushes.push_back(CreateSolidBrush(WHITE)); // BlockBar
	_brushes.push_back(CreateSolidBrush(RGB(101, 3, 62))); // Player
	_brushes.push_back(CreateSolidBrush(RGB(0, 191, 255))); // Item

	_pens.push_back(CreatePen(1, 3, RGB(0, 0, 0)));
	_pens.push_back(CreatePen(1, 3, RGB(101, 3, 62)));
	_pens.push_back(CreatePen(1, 3, RGB(0, 191, 255)));
}

ArkBlock::~ArkBlock()
{
	for (auto brush : _brushes)
	{
		DeleteObject(brush);
	}
}

void ArkBlock::Update()
{
	RectCollider::Update();
}

void ArkBlock::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_curType)]);
	_curPen = static_cast<int>(_curType);

	RectCollider::Render(hdc);


}
