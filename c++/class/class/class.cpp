#include <iostream>

using namespace std;

// Class
// 클래스로 객체를 만들 수 있음
// 객체는 기능과 속성을 가지고 있음

// 객체 : 기능(멤버변수, attribute)과 속성(멤버함수, method)을 갖고, 메모리에 올라와 있는 데이터

// 절차지향 vs 객체지향
// 객체지향의 특징
// 은닉성(캡슐화)
// 상속성
// 다형성

class Player
{
public:
	int hp;
	int atk;

private:

};

class Car
{
public:
	
	// Car의 기능 : 멤버함수
	// 멤버함수를 호출하려면 객체가 있어야한다.
	// 멤버함수는 private 속성에 접근(수정, 읽기)를 할 수 있는 방법을 열어준다.

	void Set(int engine, int handle, int wheel, int door)
	{
		// 예외처리
		if (engine < 0) return;
		if (engine > 2) return;

		_engine = engine;
		_handle = handle;
		_wheels = wheel;
		_doors = door;
	}

public:
	int _engine;
	int _wheels;

private:
	int _handle;
	int _doors;
};


int main()
{


	return 0;
}