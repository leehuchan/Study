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

	// ������Ʈ ����
	// 1. �ڵ��� ���뼺
	shared_ptr<Barrel>		   _barrel;


	// ������Ʈ Ǯ��(�������� ����� ��)
	// �Ҵ� - ������ �ּ�ȭ �ϱ� ���ؼ�, �̸� �������� ���߿� ������ ���� �� ����� ��
	UINT					   _poolCount;
	vector<shared_ptr<Ball>>   _balls;
	// Vector					   _ballDir;
	float					   _theta;


	float					   _speed;

	// Vector _gravity = Vector(0, 1);
	bool _isActive = true;
};