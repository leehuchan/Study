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
	cout << "Boss�� �����߽��ϴ�." << endl;

	cout << name << "�� HP : " << hp << endl;
	cout << name << "�� ATK : " << atk << endl << endl;
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
	cout << this->_name << "��(��) " << victim->GetName() << "���� " << this->_atk << "��ŭ �������� �������ϴ�." << endl;
	cout << victim->GetName() << "�� ���� HP : " << _vHp << endl;
	cout << victim->GetName() << "��(��) ���������ϴ�." << endl;
}

void Boss::Attacked(Creature& attacker)
{

	attacker.takeDamaged(this);
	cout << attacker.GetName() << "���� " << attacker.GetAtk() << "��ŭ ���ظ� �Ծ����ϴ�." << endl;

	if (m.count(attacker.GetName()) == 0)
	{
		m[attacker.GetName()] = attacker.GetAtk();
		cout << attacker.GetName() << "�� ���� ������ : " << m[attacker.GetName()] << endl;
	}
	else
	{
		m[attacker.GetName()] += attacker.GetAtk();
		cout << attacker.GetName() << "�� ���� ������ : " << m[attacker.GetName()] << endl;
	}

	cout << "Boss�� ���� ü�� : " << this->_hp << endl << endl;
}

void Boss::end()
{
	if (this->IsDead())
	{
		cout << "Boss�� ���������ϴ�." << endl << endl;
		Sleep(1000);
		cout << "Player ���� �¸��߽��ϴ�." << endl << endl;

		vector<pair<string, int>>v(m.begin(), m.end());

		sort(v.begin(), v.end());


		Sleep(3000);
		system("cls");

		cout << "���� ������ ����" << endl;

		for (int i = 0; i < 4; i++)
		{
			cout << i+1 << ". " << v[i].first << endl;
			cout << "���� ������ : " << v[i].second << endl << endl;

		}
		
	}
}
