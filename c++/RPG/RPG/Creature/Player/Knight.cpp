#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk)
	:Player(name, hp, atk)
{
	cout << "�÷��̾� " << name << "(��)�� �����ϼ̽��ϴ�." << endl;
	cout << name << "�� HP : " << hp << endl;
	cout << name << "�� ATK : " << atk << endl << endl;
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	cout << _name << " Knight Attack!!!" << endl;
	other->TakeDamage(_atk);
}