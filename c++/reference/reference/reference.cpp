#include <iostream>

using namespace std;

// Reference : 참조
// (자료형)& (참조이름) = (초기화);
// 크기 : 포인터와 동일

// 어셈블리어 관점에서는 포인터와 참조는 동일한 작업

// C++ 관점
// ptr
// 1. 위험하다.(nullptr에 접근, 초기화 되지않는 영역 접근 가능)
// 2. 쓰기 어려움

// ref
// 1. 누군가의 별칭
// -> nullptr 참조가 불가능함
// -> 반드시 유효한 변수의 별명이여야 함.

// ptr 장점
// nullptr을 가리킬 수 있다.

void PrintRef(int& ref)
{
	cout << ref << endl;

}


int main()
{
	int aInt = 1;
	int* ptr = &aInt;
	int& ref = aInt;

	ref++;
	(*ptr)++;

	PrintRef(aInt);
}