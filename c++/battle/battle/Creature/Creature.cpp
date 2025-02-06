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