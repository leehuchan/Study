#include "pch.h"

#include "Player.h"
#include "../Creature.h"

// cpp ����

Player::Player(string name, int hp, int atk)
	: Creature(name, hp, atk)
{

}

Player::~Player()
{

}

void Player::Attack(Creature* victim)
{

}
