#include "pch.h"
#include "Boss.h"

#include <Windows.h>

#include <algorithm>
#include <vector>

Boss::Boss()
	: Boss("Boss", 50, 5)
{

}

Boss::Boss(string name, int hp, int atk)
	:Monster(name, hp, atk)
{
	cout << "Boss가 출현했습니다." << endl;

	cout << name << "의 HP : " << hp << endl;
	cout << name << "의 ATK : " << atk << endl << endl;
}

Boss::~Boss()
{
	// m.erase(m.begin(), m.end());
}

void Boss::Attack(Creature* victim)
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
	cout << victim->GetName() << "이(가) 쓰러졌습니다." << endl;
}

void Boss::Attacked(Creature& attacker)
{

	attacker.takeDamaged(this);
	cout << attacker.GetName() << "에게 " << attacker.GetAtk() << "만큼 피해를 입었습니다." << endl;

	if (m.count(attacker.GetName()) == 0)
	{
		m[attacker.GetName()] = attacker.GetAtk();
		cout << attacker.GetName() << "의 누적 데미지 : " << m[attacker.GetName()] << endl;
	}
	else
	{
		m[attacker.GetName()] += attacker.GetAtk();
		cout << attacker.GetName() << "의 누적 데미지 : " << m[attacker.GetName()] << endl;
	}

	cout << "Boss의 남은 체력 : " << this->_hp << endl << endl;
}

void Boss::end()
{
	if (this->IsDead())
	{
		cout << "Boss가 쓰러졌습니다." << endl << endl;
		Sleep(1000);
		cout << "Player 팀이 승리했습니다." << endl << endl;

		vector<pair<string, int>>v(m.begin(), m.end());

		sort(v.begin(), v.end());


		Sleep(3000);
		system("cls");

		cout << "누적 데미지 순위" << endl;

		for (int i = 0; i < 4; i++)
		{
			cout << i+1 << ". " << v[i].first << endl;
			cout << "누적 데미지 : " << v[i].second << endl << endl;

		}
		
	}
}
