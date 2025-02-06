#pragma once

#include "Scene/CannonScene.h"

class Barrel;
class Ball;

class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire(function<void(void)> fn);

	shared_ptr<CircleCollider> GetCollider() { return _body; }
	vector<shared_ptr<Ball>> GetBalls() { return _balls; }
	bool IsCollision(shared_ptr<Ball> ball);

private:
	shared_ptr<CircleCollider> _body;

	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;

	// 컴포넌트 패턴
	// 1. 코드의 재사용성
	shared_ptr<Barrel>		   _barrel;


	// 오브젝트 풀링(번식지를 만드는 것)
	// 할당 - 해제를 최소화 하기 위해서, 미리 만들어놓고 나중에 쓸일이 없을 때 지우는 것
	UINT					   _poolCount;
	vector<shared_ptr<Ball>>   _balls;
	// Vector					   _ballDir;
	float					   _theta;


	float					   _speed;

	// Vector _gravity = Vector(0, 1);
	bool _isActive = true;
};