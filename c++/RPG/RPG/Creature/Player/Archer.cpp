#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int atk)
	:Player(name, hp, atk)
{
	cout << "플레이어 " << name << "(을)를 선택하셨습니다." << endl;
	cout << name << "의 HP : " << hp << endl;
	cout << name << "의 ATK : " << atk << endl << endl;
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	cout << _name << " archer Attack!!!" << endl;
	other->TakeDamage(_atk);
}