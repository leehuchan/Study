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

void Goblin::Attack(Creature* victim)
{
	int _vHp;
	_vHp = victim->GetHp();

	_vHp -= this->_atk;
	victim->SetHp(_vHp);

	if (_vHp < 0)
	{
		_vHp = 0;
		victim->SetHp(_vHp);
	}

	cout << this->_name << "��(��) " << victim->GetName() << "���� " << this->_atk << "��ŭ �������� �������ϴ�." << endl;
	cout << victim->GetName() << "�� ���� HP : " << _vHp << endl;

	if (victim->IsDead())
	{
		cout << this->_name << "��(��) �̰���ϴ�." << endl << endl;
		return;
	}
}

bool Goblin::IsAllDead(Goblin arr[], int size)
{
	bool allDead = true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].IsDead() == false)
			return false;
	}

	return allDead;
}
