#include "pch.h"
#include <Windows.h>

#include "../Creature.h"
#include "Monster.h"
#include "Goblin.h"

Goblin::Goblin()
	: Monster("Goblin", 50, 5)
{
}

Goblin::Goblin(string name, int hp, int atk)
	:Monster(name, hp, atk)
{
	cout << "몬스터 " << name << " 1 마리가 출현했습니다." << endl;
	cout << name << "의 HP : " << hp << endl;
	cout << name << "의 ATK : " << atk << endl << endl;
}

Goblin::~Goblin()
{

}

void Goblin::Attack(Creature* other)
{
	cout << _name << " archer Attack!!!" << endl;
	other->TakeDamage(_atk);
}