#include "framework.h"
#include "Cannon.h"

#include "Barrel.h"
#include "Ball.h"


float Dot(Vector vector1, Vector vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
};

Cannon::Cannon()
{
	_speed = 10.0f;

	_body = make_shared<CircleCollider>(CENTER, 50);

	_barrel = make_shared<Barrel>(_body);

	_poolCount = 30;
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_balls.push_back(ball);
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_body->Update();
	_barrel->Update();
	
	for (auto ball : _balls)
	{
		ball->Update();
	}

	// 등가속
	// _ballDir += _ballDir * 0.1f;

	// _theta += 0.05f;
	
	// 진자운동
	//_ball->AddForce(Vector(0, 3 * sinf(_theta)));
	//_ball->AddForce(Vector(1, 0));

	_delay += 0.1f;

	// 중력가속도
	// _gravity += _gravity * 0.01f;
}

void Cannon::Render(HDC hdc)
{
	if (_isActive == false) return;

	_barrel->Render(hdc);
	_body->Render(hdc);

	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
}

void Cannon::Move()
{
	if (GetKeyState('A') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(-1, 0) * _speed);
	}

	if (GetKeyState('D') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(1, 0) * _speed);
	}

	if (GetKeyState('W') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() - 0.1f);

	}

	if (GetKeyState('S') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() + 0.1f);
	}


}

void Cannon::Fire(function<void(void)> fn) // 함수를 객체로
{
	if (_delay < _attackSpeed)
		return;

	auto iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<Ball> ball)->bool 
		{
			if (ball->isActive == false)
				return true;
			return false;
		});
	if (iter == _balls.end()) return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		(*iter)->SetPos(_barrel->GetMuzzle());

		(*iter)->isActive = true;

		_delay = 0.0f;

		// 마우스 쪽으로 바로 발사
		//float theta1 = _barrel->GetAngle();

		//float theta2 = atan2f(mousePos.y - _barrel->GetMuzzle().y, mousePos.x - _barrel->GetMuzzle().x);

		// 삼각함수의 덧셈정리
		//float x1 = cosf(theta1) * cosf(theta2) - sinf(theta1) * sinf(theta2);
		//float y1 = sinf(theta1) * cosf(theta2) + cosf(theta1) * sinf(theta2);


		// (*iter)->Fire(Vector(x1, y1));

		(*iter)->Fire(_barrel->GetDir());

		if (fn != nullptr)
			fn();
	}

}

bool Cannon::IsCollision(shared_ptr<Ball> ball)
{
	if (_body->IsCollision(ball->GetCollider()))
	{
		ball->isActive = false;
		_isActive = false;
		return true;
	}

	return false;
}