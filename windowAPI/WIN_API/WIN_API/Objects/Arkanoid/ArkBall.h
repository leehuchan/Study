#pragma once
class Bar;

class ArkBall : public CircleCollider
{
public:
	friend class Bar;

	ArkBall(shared_ptr<Bar> bar);
	~ArkBall();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	void Reset();

	void Fixed();
	void Fire(Vector dir);

	void Reflection_Wall();

	void SetDir(Vector dir) { _dir = dir.NormalVector(); }
	Vector GetDir() { return _dir; }

	shared_ptr<CircleCollider> GetCollider() { return _circle; }

	bool IsFired() { return _isFired; }
	bool& IsActive() { return _isActive; }

	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }

private:
	shared_ptr<CircleCollider> _circle;

	Vector _pos = { 0,0 };
	Vector _dir = { 0,0 };
	float _speed = 7.0f;

	weak_ptr<Bar> _bar;

	bool _isFired = false;
	bool _isActive = false;
};

