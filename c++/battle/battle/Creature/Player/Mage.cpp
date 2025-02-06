#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk)
	:Player(name, hp, atk)
{
	cout << "플레이어 " << name << "(을)를 선택하셨습니다." << endl;
	cout << name << "의 HP : " << hp << endl;
	cout << name << "의 ATK : " << atk << endl << endl;
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

	cout << this->_name << "이(가) " << victim->GetName() << "에게 " << this->_atk << "만큼 데미지를 입혔습니다." << endl;
	cout << victim->GetName() << "의 남은 HP : " << _vHp << endl;

	if (victim->IsDead())
	{
		cout << endl;
		cout << this->_name << "이(가) 이겼습니다." << endl << endl;
		return;
	}
}
