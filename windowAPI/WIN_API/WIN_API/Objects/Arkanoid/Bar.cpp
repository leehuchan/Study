#include "framework.h"
#include "Bar.h"

#include "ArkBall.h"

Bar::Bar()
{
	_pos = CENTER + Vector(0, 200);
	_body = make_shared<RectCollider>(_pos, Vector(200, 20));
}

Bar::~Bar()
{
}

void Bar::Init() // ball °´Ã¼ »ý¼º
{
	for (int i = 0; i < 2; i++)
	{
		auto ball = make_shared<ArkBall>(shared_from_this());
		ball->_isActive = false;
		ball->_isFired = false;

		_balls.push_back(ball);
	}

	_balls[0]->_isActive = true;
	_hp = 1.0f;
}

void Bar::Update()
{
	_body->Update();

	for (auto ball : _balls)
	{
		ball->Update();
	}
	IsFall();
}

void Bar::Render(HDC hdc)
{
	_body->Render(hdc);
	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
}

void Bar::Input()
{
	_delayTime += 0.1f;

	if (GetKeyState('A') & 0x8000)
	{
		_pos += Vector(-1, 0) * 10;
	}

	if (GetKeyState('D') & 0x8000)
	{
		_pos += Vector(1, 0) * 10;
	}

	_body->SetCenter(_pos);

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (_delayTime > 3.0f)
		{
			_delayTime = 0.0f;

			auto ballIter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<ArkBall> a)-> bool
				{
					if (a->IsFired())
						return false;
					return true;
				});

			if (ballIter != _balls.end())
				(*ballIter)->Fire(Vector(0, -1));
		}
	}
}

void Bar::IsFall()
{
	for (auto& ball : _balls)
	{
		if (!ball->GetActive())
			continue;

		if (ball->GetCenter().y + ball->GetRadius() >= WIN_HEIGHT)
		{
			SetHp(GetHp() - 0.2);
		}
	}
}
