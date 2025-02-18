#pragma once
#include "Player.h"

class Knight : public Player
{
public:
	Knight(string name, int hp, int atk);
	~Knight();

	virtual void Attack(Creature* victim) override;

private:

};

