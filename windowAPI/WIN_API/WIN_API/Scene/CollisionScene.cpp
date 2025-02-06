#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle = make_shared<CircleCollider>(Vector(450, 500), 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 60);

	// rect, moving »ý¼º
	_rect = make_shared<RectCollider>(Vector(600, 600), Vector(200, 200));
	_movingRect = make_shared<RectCollider>(Vector(0, 0), Vector(60,60));


}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	//_movingCircle->SetCenter(mousePos);


	//if (_circle->IsCollision(_movingCircle))
	//{
	//	_circle->SetRed();
	//}
	//else
	//{
	//	_circle->SetGreen();
	//}

	// _movingRect->SetCenter(mousePos);

	if (_rect->IsCollision(mousePos))
	{
		_rect->SetRed();
	}
	else
	{
		_rect->SetGreen();
	}

	//if (_rect->IsCollision(_movingRect))
	//{
	//	_rect->SetRed();
	//}
	//else
	//{
	//	_rect->SetGreen();
	//}

	//_circle->Update();
	//_movingCircle->Update();

	_rect->Update();
	_movingRect->Update();
}

void CollisionScene::Render(HDC hdc)
{
	//_circle -> Render(hdc);
	//_movingCircle->Render(hdc);
	_rect->Render(hdc);
	_movingRect->Render(hdc);
}