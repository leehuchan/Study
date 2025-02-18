#pragma once
class Creature
{
public:
	Creature(string name, int hp, int atk);
	~Creature();

	virtual void Attack(Creature* victim) abstract;

	bool IsDead();


	// C# getset
	string GetName() { return _name; }
	void SetName(string name) { _name = name; }

	int GetHp() { return _hp; }
	void SetHp(int hp) { _hp = hp; }

	int GetAtk() { return _atk; }
	void SetAtk(int atk) { _atk = atk; }

	void takeDamaged(Creature* victim);



protected:
	string _name;
	int _hp;
	int _atk;
};