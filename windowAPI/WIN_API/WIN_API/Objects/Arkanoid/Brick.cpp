#include "framework.h"
#include "Brick.h"

Brick::Brick(Vector size)
{
	_pos = CENTER;
	_body = make_shared<RectCollider>(CENTER, Vector(100, 30));
}

Brick::~Brick()
{
}

void Brick::Update()
{
	if (!_isActive)
		return;

	_body->Update();

	_body->SetCenter(_pos);
}

void Brick::Render(HDC hdc)
{
	if (_isActive)
		_body->Render(hdc);
}

void Brick::Break_Brick()
{
	_isActive = false;
}