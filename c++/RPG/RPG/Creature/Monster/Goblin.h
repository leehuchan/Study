#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
	Goblin();

	Goblin(string name, int hp, int atk);
	~Goblin();

	virtual void Attack(Creature* other) override;


private:
	// private 멤버변수에 접근할 수 있는 함수는 멤버 함수밖에 없음

};

