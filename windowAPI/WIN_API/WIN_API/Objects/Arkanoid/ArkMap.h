#pragma once

class Brick;
class ArkBall;
class Bar;

class ArkMap
{
public:
	ArkMap();
	~ArkMap();

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<Brick>>> GetBricks() { return _bricks; }

	void IsCollision_Bricks(shared_ptr<ArkBall> ball);

private:
	vector<vector<shared_ptr<Brick>>> _bricks;

	Vector _brickSize = Vector(80, 20);

	int _countX = 9;
	int _countY = 3;

	Vector _brickGap = Vector(30, 30);

};

