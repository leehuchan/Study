#pragma once
#include "../Creature.h"

class Monster : public Creature
{
public:
	Monster(string name, int hp, int atk);
	~Monster();
};