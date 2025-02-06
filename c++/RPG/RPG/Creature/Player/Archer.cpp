#include "pch.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int atk)
	:Player(name, hp, atk)
{
	cout << "�÷��̾� " << name << "(��)�� �����ϼ̽��ϴ�." << endl;
	cout << name << "�� HP : " << hp << endl;
	cout << name << "�� ATK : " << atk << endl << endl;
}

Archer::~Archer()
{
}

void Archer::Attack(Creature* other)
{
	cout << _name << " archer Attack!!!" << endl;
	other->TakeDamage(_atk);
}