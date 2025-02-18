#pragma once

class ArkBall;

class Bar : public enable_shared_from_this<Bar>
{
public:
	Bar();
	~Bar();

	void Init();

	void Update();
	void Render(HDC hdc);

	void Input();

	void IsFall();


	Vector GetPos() { return _pos; }
	shared_ptr<RectCollider> GetCollider() { return _body; }
	vector<shared_ptr<ArkBall>> GetBalls() { return _balls; }

	float GetHp() { return _hp; }
	void SetHp(float hp) { _hp = hp; }

private:
	float _delayTime = 0.0f;

	shared_ptr<RectCollider> _body;

	Vector _pos;

	vector<shared_ptr<ArkBall>> _balls;

	float _hp = 1.0f;
};