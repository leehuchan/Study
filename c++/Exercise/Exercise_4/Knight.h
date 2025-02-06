#pragma once

class Knight
{
public:
	Knight();
	Knight(int hp, int maxHp);
	~Knight();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

public:
	int _hp;
	int _maxHp;
	int _attack;
};

