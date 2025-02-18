#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/Arkanoid/Bar.h"
#include "Objects/Arkanoid/ArkBall.h"
#include "Objects/Arkanoid/Brick.h"
#include "Objects/Arkanoid/ArkMap.h"
#include "Objects/Arkanoid/HpBar.h"

ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<Bar>();
	_map = make_shared<ArkMap>();

	_bar->Init();

	_ui_hpBar = make_shared<HpBar>(CENTER + Vector(0, 300), Vector(600, 30));
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
	_bar->Input();

	_map->Update();
	_ui_hpBar->Update();


	_ui_hpBar->SetValue(_bar->GetHp());

	for (auto ball : _bar->GetBalls())
	{
		if (ball->IsFired() == false)
			continue;

		_map->IsCollision_Bricks(ball);
	}
}

void ArkanoidScene::Render(HDC hdc)
{
	_bar->Render(hdc);
	_map->Render(hdc);

	// UI는 항상 최후위
	_ui_hpBar->Render(hdc);
}
