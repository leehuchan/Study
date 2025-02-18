#include "framework.h"
#include "ArkMap.h"

#include "Brick.h"
#include "ArkBall.h"
#include "Bar.h"

ArkMap::ArkMap()
{
	_bricks.resize(_countY);

	Vector offset;
	int x = ((_brickSize.x + _brickGap.x) * _countX) / 2.0f;

	Vector temp = CENTER;
	offset.x = temp.x - x;
	offset.y = 200.0f;

	for (int y = 0; y < _countY; y++)
	{
		for (int x = 0; x < _countX; x++)
		{
			shared_ptr<Brick> brick = make_shared<Brick>(_brickSize);

			Vector brickPos;
			brickPos.x = (_brickSize.x + _brickGap.x) * x;
			brickPos.y = (_brickSize.y + _brickGap.y) * y;

			brick->SetPos(brickPos + offset);
			brick->_isActive = true;
			_bricks[y].push_back(brick);

		}
	}
}

ArkMap::~ArkMap()
{
}

void ArkMap::Update()
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			brick->Update();

		}
	}
}

void ArkMap::Render(HDC hdc)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			brick->Render(hdc);
		}
	}
}

void ArkMap::IsCollision_Bricks(shared_ptr<ArkBall> ball)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			if (brick->_isActive == false)
				continue;

			if (brick->GetCollider()->IsCollision(ball->GetCollider()) == false)
				continue;

			brick->Break_Brick();

			// 좌우 사이에 있었다.
			if (ball->GetPos().x < brick->GetCollider()->Right() && ball->GetPos().x > brick->GetCollider()->Left())
			{
				Vector curDir = ball->GetDir();
				curDir.y *= -1.0f;

				ball->SetDir(curDir);
			}
			// 위 아래 사이에 있었다.
			else
			{
				Vector curDir = ball->GetDir();
				curDir.x *= -1.0f;

				ball->SetDir(curDir);
			}
		}
	}
}