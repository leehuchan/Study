#pragma once
#include "ArkBlock.h"

#define MAX_X 7
#define MAX_Y 3

class Arkanoid
{
public:
	Arkanoid();
	~Arkanoid();

	void Update();
	void Render(HDC hdc);

	void CreateArk();
	ArkBlock::Type GetBlockType(Vector pos);
	void SetBlockType(Vector pos, ArkBlock::Type type);


private:
	vector<vector<shared_ptr<ArkBlock>>> _arkblocks;
};

