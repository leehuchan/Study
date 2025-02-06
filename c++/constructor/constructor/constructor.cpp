﻿#include <iostream>

using namespace std;

// 생성자의 역할
// 멤버변수의 초기화
// 세팅

class Player
{
public:
	// 기본 생성자
	// 정의하지 않으면 암시적으로 컴파일러가 생성
	// 다른 생성자(타입변환생성자)가 있을 경우 자동으로 생성하지 않음

	Player()
		// 빠른 초기화 영역 (Initialize List)
		: _maxHp(100)
		, _hp(0)
		, _atk(0)

	{
		// 늦은 초기화 영역
		// _hp = 0; // 대입연산자
		// _atk = 0;
		cout << "기본생성자 호출" << endl;
	}

	// 타입변환생성자 (매개변수가 있는 생성자)
	Player(int hp)
		: _maxHp(hp)
		, _hp(hp)
		, _atk(0)
	{
	}

	// 복사생성자, 복사대입생성자
	// 기본생성자와 마찬가지로 암시적으로 만들어주는 생성자
	Player(const Player& other)
		: _maxHp(other._maxHp)
		, _hp(other._hp)
		, _atk(other._atk)
	{
		//p = other._hp;
		// _atk = other._atk;
		// 얕은 복사
	}

private :
	int _hp;
	int _atk;

	const int _maxHp;
	// int& _temp;
};


int main()
{
	// 객체 : 속성과 기능을 갖고 ,메모리에 할당되어 있는 ( 클래스로 만든 ) 애
    // 객체화, 인스턴스화 : 클래스로 메모리에 할당시키는 작업

	Player p = 100;
	// Player P(100);

	Player p2 = p;
	// Player p2(p);

	return 0;
}
