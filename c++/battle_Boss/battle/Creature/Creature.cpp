#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int atk)
	: _name(name), _hp(hp), _atk(atk)
{

}

Creature::~Creature()
{
	
}

bool Creature::IsDead()
{
	return _hp <= 0;
}

void Creature::takeDamaged(Creature* victim)
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
}
