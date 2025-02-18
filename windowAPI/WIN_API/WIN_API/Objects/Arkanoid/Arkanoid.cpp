#include "framework.h"
#include "Arkanoid.h"

#include "ArkBlock.h"

Arkanoid::Arkanoid()
{
	// offset : 기준점(원점)에서 떨어뜨려놓는 Vector
	Vector offset = Vector(80, 20);

	_arkblocks.resize(MAX_Y);
	for (int y = 0; y < MAX_Y; y++)
	{
		_arkblocks[y].reserve(MAX_X);
		for (int x = 0; x < MAX_X; x++)
		{
			shared_ptr<ArkBlock> block = make_shared<ArkBlock>();
			Vector pos;
			pos.x = x * 150;
			pos.y = y * 23;
			block->SetCenter(pos + offset);
			block->SetType(ArkBlock::Type::BLOCKBar);

			_arkblocks[y].push_back(block);
		}
	}
	CreateArk();
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	for (auto blockV : _arkblocks)
	{
		for (auto block : blockV)
		{
			block->Update();
		}
	}
}

void Arkanoid::Render(HDC hdc)
{
	for (auto blockV : _arkblocks)
	{
		for (auto block : blockV)
		{
			block->Render(hdc);
		}
	}
}

void Arkanoid::CreateArk()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			_arkblocks[y][x]->SetType(ArkBlock::Type::BLOCKBar);
		}
	}
}

ArkBlock::Type Arkanoid::GetBlockType(Vector pos)
{
	return _arkblocks[pos.y][pos.x]->GetBlockType();
}

void Arkanoid::SetBlockType(Vector pos, ArkBlock::Type type)
{
	_arkblocks[pos.y][pos.x]->SetType(type);

}
