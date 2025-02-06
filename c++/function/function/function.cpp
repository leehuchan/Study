#include <iostream>

using namespace std;

/*
함수
// 매개변수를 넣고 반환을 받는 것

함수 시그니처
(반환자료형) 함수이름 (매개변수);

*/

// Stack 영역
// 지역변수
// 매개변수
// 반환주소 값

// 스택 프레임
/*
함수가 호출되면 스택에는 함수의 매개변수, 호출이 끝난 뒤 돌아갈 반환 주소값, 함수에서 선언된 지역 변수 등이 저장됩니다.

이렇게 스택 영역에 차례대로 저장되는 함수의 호출 정보를 스택 프레임(stack frame)이라고 합니다.

이러한 스택 프레임 덕분에 함수의 호출이 모두 끝난 뒤에, 해당 함수가 호출되기 이전 상태로 되돌아갈 수 있습니다.
*/
// FIFO

void HelloWorld(int temp)
{
	cout << "Hello World" << temp << endl;
}
// Call By Value
int Add(int a, int b)
{
	int c = a + b;
	// main[반환주소 값, 지역 변수(aInt(1), bInt(2)), 매개변수()] ADD[반환주소값, 지역변수(c(3)), 매개변수(a(1),b(2))]

	cout << c << endl;

	return c;
}

// 함수 오버로딩
// 함수 이름이 같고, 매개변수의 자료형이나 개수가 다른 것

int Add(int a, int b, int c)
{
	int d = Add(a, b) + c;

	cout << d << endl;

	return d;
}

// 기본인자
// 맨 뒤의 인자부터 정의 해줘야한다.
int Add(int a, int b, int c, int d, int e = 4)
{
	int f = Add(a,b,c) + d + e;

	cout << f << endl;

	return f;
}

/*
int Add(int a, int b, int c, int d)
{
	int f = a + b + c + d;

	cout << f << endl;

	return 0;
}
*/

// 재귀호출 : 함수가 자기 자신을 호출

int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);

}


int main()
{
	int aInt = 1;
	int bInt = 2;
	int cInt = 3;
	int dInt = 4;
	int eInt = 5;


	// main[반환주소 값, 지역 변수(aInt(1), bInt(2)), 매개변수()]
	if (Add(aInt, bInt, cInt, dInt) == 14)
	{
		cout << "14 입니다." << endl;
	}

	cout << Factorial(5) << endl;

	return 0;
}