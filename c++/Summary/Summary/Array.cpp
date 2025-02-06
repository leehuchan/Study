#include <iostream>

using namespace std;

// 1. 상수 선언방법 3가지
// 선언과 동시에 초기화
// #define 매크로
// const
// enum

// 2. 포인터 연산

// 3. 배열, 배열과 포인터의 상관관계

#define PI 3.141592f
#define Declare(k) float temp(k)

// 정수형 상수
// 열거형
enum PlayerState
{
	IDLE = 5,
	RUN,
	FALLING,
	SLEEPING
};

// 포인터
// (자료형)* (변수이름): 포인터 선언
// (변수) * (변수) : 곱셈연산자
// *(변수) : 간접연산자
// (자료형)** (변수이름): 이중포인터

// (변수) & (변수) : 비트 And연산자
// (변수) && (변수) : And 연산자
// (자료형)& (변수이름) = 초기화 : Reference 선언
// &(변수) : 주소연산자

// 포인터 연산자
// (ptr + 1) => 포인터의 자료형의 따라

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size)
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << arr[y][x] << endl;
		}
	}
}

int main()
{
	// const(자료형) : 상수 취급 => 쓰기 불가능
	const int temp = 1;

	PlayerState curState = PlayerState::IDLE;

	// const (자료형)* const : 읽기 전용
	const int* ptr = &temp;

	// const 자료형& : 읽기 전용
	const int& ref = temp;

	int aInt = 1;
	int* ptr2 = &aInt;

	cout << (ptr2) << endl;

	cout << (ptr2) << endl;

	cout << (ptr2 + 1) << endl;

	int arr[10]; // 정적배열
	// [index] : 임의접근연산자
	// 배열에 임의접근하는데 걸리는 시간복잡도는 상수

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	ptr2 = &arr[0];

	PrintArr(&arr[0], 10);

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << *(ptr2 + i) << endl;
	//	cout << ptr2[i] << endl;
	//	cout << arr[i] << endl;
	//}
	


	return 0;
}