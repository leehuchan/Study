#include <iostream>

using namespace std;

// 프로그래밍

// 객체 : 속성과 기능을 갖고 메모리에 할당되어있는 것
// 객체화 : 클래스 자료형을 메모리에 할당하는 것
// 인스턴스 : 속성과 기능을 가지지 않아도 메모리에 할당되어있는 것
// 인스턴스화 : 메모리에 할당하는 것

// 1. 객체지향의 3속성
// 은닉성
// -> 외부에서 쉽게(직접) 접근해서 바꾸지 못하게 하려고
// -> 멤버함수 내에서만 통제시키려고
// 접근지정자 : public(어디에서든 접근) / protected(멤버함수, 자식의 멤버함수) / privatte(멤버함수, friend)
struct Vector // 수학
{
public:
	float x;
	float y;
};

class Car // 객체(속성, 기능)
{
public:
	// 멤버함수
	// - 기능
	// 멤버변수에 직접 접근 -> 속성을 다루는 기능
	// 멤버함수는 객체가 있어야 호출이 가능
	void PrintCar() { cout << _engine << endl; }
	int GetEngine() { return _engine; }
	void SetEngine(int engine) { this->_engine = engine; }

private:
	// 멤버변수
	// -속성
	int _engine;
	int _handle;
	int _wheels;
	int _doors;
};

int main()
{
	Car car;

	// 사용자 사용 코드

	car.SetEngine(5);
	cout << car.GetEngine() << endl;

	return 0;
}