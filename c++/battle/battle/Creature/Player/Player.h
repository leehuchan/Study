#pragma once
#include "../Creature.h"

// h�� �����
// h, cpp ����
// => ��Ŀ

// ���漱��
// class Creature;
// #include �� ���� �ʴ� ����
// ���漱���� �ƴ� #include�� �ϰ� �Ǹ� #include�� ���� �� �ҷ��;� �ϱ� ����

class Player : public Creature
{
public:
	Player(string name, int hp, int atk);
	~Player();

	// void TakeDamage(int amount);


};

