#pragma once
#include "../Creature.h"


class Player : public Creature
{
public:
	Player(string name, int hp, int atk);
	~Player();
};
