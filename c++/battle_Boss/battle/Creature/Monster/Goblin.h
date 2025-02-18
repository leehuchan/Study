#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();

	Goblin(string name, int hp, int atk);
	~Goblin();

	virtual void Attack(Creature* victim) override;

	bool IsAllDead(Goblin arr[], int size);


private:
	// private ��������� ������ �� �ִ� �Լ��� ��� �Լ��ۿ� ����

};

