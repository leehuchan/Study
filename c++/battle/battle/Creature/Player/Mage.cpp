#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk)
	:Player(name, hp, atk)
{
	cout << "�÷��̾� " << name << "(��)�� �����ϼ̽��ϴ�." << endl;
	cout << name << "�� HP : " << hp << endl;
	cout << name << "�� ATK : " << atk << endl << endl;
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* victim)
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
		cout << endl;
		cout << this->_name << "��(��) �̰���ϴ�." << endl << endl;
		return;
	}
}
