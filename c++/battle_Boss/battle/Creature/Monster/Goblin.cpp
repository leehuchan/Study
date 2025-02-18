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

	cout << this->_name << "이(가) " << victim->GetName() << "에게 " << this->_atk << "만큼 데미지를 입혔습니다." << endl;
	cout << victim->GetName() << "의 남은 HP : " << _vHp << endl;

	if (victim->IsDead())
	{
		cout << this->_name << "이(가) 이겼습니다." << endl << endl;
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
