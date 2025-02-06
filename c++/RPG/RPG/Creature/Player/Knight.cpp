#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk)
	:Player(name, hp, atk)
{
	cout << "플레이어 " << name << "(을)를 선택하셨습니다." << endl;
	cout << name << "의 HP : " << hp << endl;
	cout << name << "의 ATK : " << atk << endl << endl;
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	cout << _name << " Knight Attack!!!" << endl;
	other->TakeDamage(_atk);
}