#pragma once
#include "Player.h"

class Mage : public Player
{
	Mage(string name, int hp, int atk);
	~Mage();

	virtual void Attack(Creature* victim) override;

};

