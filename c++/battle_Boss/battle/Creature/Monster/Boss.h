#pragma once
#include "Monster.h"
#include "vector"
#include "map"

class Boss : public Monster
{
public:
	Boss();

	Boss(string name, int hp, int atk);

	~Boss();

	virtual void Attack(Creature* victim) override;

	virtual void Attacked(Creature& attaker);

	int getMaxHp() { return _maxHp; }

	void end();


private:
	map<string, int> m;
	map<string, int>::iterator iter;

	int _maxHp = 2000;

};