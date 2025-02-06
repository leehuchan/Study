#pragma once
#include "../Creature.h"

// h는 선언부
// h, cpp 결합
// => 링커

// 전방선언
// class Creature;
// #include 를 하지 않는 이유
// 전방선언이 아닌 #include로 하게 되면 #include를 여러 번 불러와야 하기 때문

class Player : public Creature
{
public:
	Player(string name, int hp, int atk);
	~Player();

	// void TakeDamage(int amount);


};

