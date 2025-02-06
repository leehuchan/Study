#include <iostream>
#include <functional>

using namespace std;

function<void(void)> fn; // Callabe 객체를 담을 수 있는 변수
void Hello()
{
	cout << "Hello World!" << endl;
}

// Functor : 함수객체
struct Functor
{
	// 함수 연산자 연산자 오버로딩
	void operator()()
	{
		cout << aInt << endl;

		cout << "Hello World" << endl;
	}

	// 속성을 가질 수 있다.
	int aInt;

};

struct Functor2
{
	int operator()()
	{
		return a + b;
	}

	int a;
	int b;
};

int main()
{
	Functor functor;
	functor.aInt = 1;
	functor();

	functor.aInt = 2;
	functor();

	Functor2 functor2;
	functor2.a = 1;
	functor2.b = 2;

	int cInt = functor2();

	cout << cInt;

	return 0;
}