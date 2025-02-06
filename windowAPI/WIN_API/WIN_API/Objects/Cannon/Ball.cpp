#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(Vector(-1000, -1000), 10);
}

Ball::~Ball()
{
}

void Ball::AddForce(Vector v)
{
	if (isActive == false) return;

	_circle->SetCenter(_circle->GetCenter() + v);
}

void Ball::Update()
{
	if (isActive == false) return;

	_circle->Update();

	_ballHasGone += _dir.Length();

	_circle->SetCenter(_circle->GetCenter() + _dir);

	// 진자운동
	Vector goV;
	//goV.x = 1 * _dir.x - sinf(_ballHasGone) * _dir.y;
	//goV.y = sinf(_ballHasGone) * _dir.x + 1 * _dir.y;

	// 유도탄
	// 외적
	//_dir;
	//Vector guided = mousePos - _circle->GetCenter();
	//float cross = _dir.Cross(guided);
	//if (abs(cross) < 0.01)
	//{
	//}
	//else if (cross < 0.0f )
	//{
	//	_dir.Rotate(-0.1f);
	//}
	//else
	//{
	//	_dir.Rotate(0.1f);
	//}

	//_circle->SetCenter(_circle->GetCenter() + _dir * 5);

	_circle->SetCenter(_circle->GetCenter() + _dir * _ballSpeed);


	//// 화면 밖에 나가는 예외 처리
	//if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x < 0
	//	|| _circle->GetCenter().y > WIN_HEIGHT || _circle->GetCenter().y < 0)
	//{
	//	isActive = false;
	//}

	// 화면 밖에 전반사
	Vector center = _circle->GetCenter();
	if (center.x < 0 || center.x > WIN_WIDTH)
		_dir.x *= -1;
	if (center.y < 0 || center.y > WIN_HEIGHT)
		_dir.y *= -1;
}

void Ball::Render(HDC hdc)
{
	if (isActive == false) return;

	_circle->Render(hdc);
}

void Ball::Fire(Vector dir)
{
	_dir = dir.NormalVector();
}

