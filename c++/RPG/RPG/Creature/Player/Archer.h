#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(string name, int hp, int atk);
	~Archer();

	virtual void Attack(Creature* victim) override;
};

