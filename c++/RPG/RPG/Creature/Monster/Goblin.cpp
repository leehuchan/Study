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
	cout << "���� " << name << " 1 ������ �����߽��ϴ�." << endl;
	cout << name << "�� HP : " << hp << endl;
	cout << name << "�� ATK : " << atk << endl << endl;
}

Goblin::~Goblin()
{

}

void Goblin::Attack(Creature* other)
{
	cout << _name << " archer Attack!!!" << endl;
	other->TakeDamage(_atk);
}