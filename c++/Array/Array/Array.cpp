﻿#include <iostream>

using namespace std;

// (변수)*(변수) : 곱셈연산자
// *(포인터 변수) : 간접연산자
// (자료형)* (변수이름) : 포인터 선언
// (변수)-> : 간접멤버연산자
// 
// (변수) && (변수) : 비교 AND 연산자
// (변수) & (변수) : 비트 AND 연산자
// &(변수) : 주소연산자

// (자료형)& (변수이름) : 참조 선언

// 매개변수, 인자 (parameter, arrgument)

// 포인터 덧셈
// 32비트 환경에서 1씩 더할 때 int* : 4만큼 더해진다.
// 64비트 환경에서 1씩 더할 때 int* : 8만큼 더해진다.


// (자료형)* (포인터변수)
// 자료형 의미
// 주소를 타고 가면 해당 자료형의 변수가 있을 것이다.
// 연산을 할 때 자료형의 크기만큼 주소값이 더해진다.

// 정적 배열
// 같은 자료형을 메모리에 연속적으로 여러 개 선언하는 방법

// 선언 방법
// (자료형) 배열이름[개수] = { 초기화 };

// 인덱스 : 색인

// 배열의 연산자
// [index] : 임의접근연산자 -> 배열의 경우 상수의 시간이 걸린다.


// 배열의 이름은 0번째 인덱스의 주소값과 같다.

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl; // cout << ptr[i] << endl; 둘이 서로 같음
	}
}

// 이차원 정적배열 출력
void PrintArr2(int arr[][3], int ysize)
{
	for (int i = 0; i < ysize; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << endl;
		}
	}
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	int* ptr = arr;

	int arrSize = sizeof(arr) / sizeof(int); // 5
	PrintArr(arr, arrSize);

	// 이차 포인터
	int** ptr2 = &ptr;

	// 이차원 배열
	int arr2[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

	PrintArr2(arr2, 3);

	return 0;
}