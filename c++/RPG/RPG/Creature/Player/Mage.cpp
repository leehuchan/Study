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

void Mage::Attack(Creature* other)
{
	cout << _name << " Mage Attack!!!" << endl;
	other->TakeDamage(_atk);
}