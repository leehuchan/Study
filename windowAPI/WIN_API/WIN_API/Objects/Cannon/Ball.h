#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void AddForce(Vector v);

	void SetPos(Vector pos) { _circle->SetCenter(pos); }
	void Fire(Vector dir);

	void Update();
	void Render(HDC hdc);

	shared_ptr<CircleCollider> GetCollider() { return _circle; }

	bool isActive = false;

private:
	shared_ptr<CircleCollider> _circle;

	float _ballHasGone = 0.0f;
	float _ballSpeed = 3;
	Vector _dir;
};