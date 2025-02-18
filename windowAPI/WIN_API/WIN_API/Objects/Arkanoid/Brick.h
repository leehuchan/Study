#pragma once
class ArkMap;

class Brick
{
	friend class ArkMap;
public:
	Brick(Vector size);
	~Brick();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	shared_ptr<RectCollider> GetCollider() { return _body; }

	void Break_Brick();


private:
	bool _isActive = false;

	shared_ptr<RectCollider> _body;
	Vector _pos;

};