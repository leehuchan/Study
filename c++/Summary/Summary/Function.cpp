#include <iostream>

using namespace std;

// (반환 자료형) 함수이름(매개변수) => 함수 시그니처

// 포인터 연산자
// *ptr : 간접연산자 => 포인터가 담고있는 주소값으로 포탈타고 들어감
// &(변수) : 주소연산자 => 변수가 담겨있는 주소값

// Stack : 컴파일 시간에 크기가 결정

// 스택 프레임
// 메모리의 스택 영역에 순서대로 저장되는 함수의 호출 정보
// 반환주소값, 매개변수, 지역변수
// 포인터, 참조

void HelloWorld()
{
	cout << "HelloWorld!" << endl;
}

// Call by Value
void AddOne(int num)
{
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3)), Add[반환주소값(&aInt), 매개변수(num : 3), 지역변수 c()]
	// main[반환주소값(), 매개변수(void), 지역변수(aInt(3)), Add[반환주소값(&aInt), 매개변수(num : 4), 지역변수 c()]
	num++;
}

// Call by Address
void AddOne(int* ptr)
{
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(3)), Add[반환주소값(&aInt), 매개변수(ptr : 0x12), 지역변수 c()]
	(*ptr)++;
	// main[반환주소값(), 매개변수(void), 지역변수((0x12)aInt(4)), Add[반환주소값(&aInt), 매개변수(ptr : 0x12), 지역변수 c()]

}

int Add(int a, int b)
{
	int c = a + b;

	// main[반환주소값(), 매개변수(void), 지역변수(aInt(cccccccc)), Add[반환주소값(), 매개변수(a 1, b 2), 지역변수 c(3)]

	cout << c << endl;

	return c;
}

// 함수 오버로딩
// 다른 버전 : 매개변수의 자료형이나 개수가 다른 것
int Add(int a, int b, int c)
{
	int d = a + b + c;
	return d;
}

// 함수 매개변수의 기본인자 -> 매개변수(인자, parameter, arrgument)
// 기본인자는 맨 뒤부터 초기화해야 함
int Add(int a, int b, int c, int d, int e = 1)
{
	int f = a + b + c + d + e;
	return f;
}

// 재귀호출 : 스택오버플로우 => 스택영역에 더 이상 할당할 수가 없다.

int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}

// 메모이제이션
int cache[200] = {};

// 피보나치 수열
int Fibonacci(int num)
{
	if (num <= 1)
		return num;

	int* ref = &cache[num];
	if (*ref != 0)
		return *ref;

	*ref = Fibonacci(num - 1) + Fibonacci(num - 2);

	if (num == 2)
		cout << "Factorial 2 계산" << endl;

	// bhgreturn Fibonacci(num - 1) + Fibonacci(num - 2);
	return *ref;
}

int main()
{
	// HelloWorld();

	// main[반환주소값(), 매개변수(void), 지역변수(aInt(cccccccc))

	int aInt = Add(1, 2);
	// aInt ... 3

	AddOne(aInt);

	cout << aInt << endl;
	// aInt 3으로 출력


	AddOne(&aInt);

	cout << aInt << endl;
	// aInt 4으로 출력

	int bInt = Add(1, 2, 3, 4);

	cout << bInt << endl;

	int cInt = Factorial(5);

	cout << cInt << endl;

	int dInt = Fibonacci(20);

	cout << dInt << endl;

	return 0;
}