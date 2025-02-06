#include <iostream>

using namespace std;

// 다형성
// 1. 멤버함수 오버라이딩
// 부모의 함수를 자식에서 재정의하는 것 (함수 시그니처가 동일 해야함)

// 2. 멤버함수 오버로딩
// 함수의 이름이 같고, 매개변수의 개수나 자료형이 다른 함수를 정의할 수 있다.

class Player
{
public:
	void Attack() { cout << "Attack" << endl; }

	void Set(int hp, int atk) { _hp = hp; _atk = atk; }

	// 연산자 오버로딩
	Player operator+(const Player& other)
	{
		Player result;
		result._hp = _hp + other._hp;
		result._atk = _atk + other._atk;
	}

protected:
	int _hp;
	int _atk;
};

class knight : public Player
{
public:
	void Attack() { cout << "Kinght" << endl; } // 함수 오버라이딩
private:

};

int main()
{
	knight knight;
	knight.Attack();

	return 0;
}