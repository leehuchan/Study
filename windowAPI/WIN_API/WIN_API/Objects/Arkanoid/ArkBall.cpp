#include "framework.h"
#include "ArkBall.h"

#include "Bar.h"

ArkBall::ArkBall(shared_ptr<Bar> bar)
	:CircleCollider(Vector(700, 550), 10)
{
	_circle = make_shared<CircleCollider>(Vector(0,0), 10.0f);

	_bar = bar;
}

ArkBall::~ArkBall()
{
}

void ArkBall::Update()
{
	if (_isActive == false)
		return;

	_circle->Update();

	_pos += _dir * _speed;
	_circle->SetCenter(_pos);


	Fixed();
	Reflection_Wall();
}

void ArkBall::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_circle->Render(hdc);
}

void ArkBall::Reset()
{
	_isActive = false;
	_isFired = false;
	Fixed();
}

void ArkBall::Fixed()
{
	if (_bar.expired() || _isFired == true)
		return;

	shared_ptr<Bar> curBar = _bar.lock();
	Vector barPos = curBar->GetPos();
	Vector barHalf = curBar->GetCollider()->GetHalfSize();

	_pos = barPos + Vector(0, -barHalf.y);
}


void ArkBall::Fire(Vector dir)
{
	_dir = dir.NormalVector();

	_isFired = true;
}

void ArkBall::Reflection_Wall()
{
	if (!_isFired)
		return;

	// 화면에 있는 벽과 충돌 시
	if (_pos.x < 0 || _pos.x > WIN_WIDTH)
		_dir.x *= -1;
	if (_pos.y < 0)
		_dir.y *= -1;
	if (_pos.y > WIN_HEIGHT)
		_isActive = false;

	// bar와 충돌 시
	if (_circle->IsCollision(_bar.lock()->GetCollider()))
	{
		Vector dir = _pos - _bar.lock()->GetPos();

		_dir = dir.NormalVector();
	}
}