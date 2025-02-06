#include <iostream>

using namespace std;

// 컴파일 4단계
// 1. 전처리기
// #붙은 것들 처리 / 주석 부분 삭제
// 2. 컴파일러
// 고수준 언어를 어셈블리어로 바꾸는 작업
// 3. 어셈블러
// 어셈블리어를 기계어로 바꾸는 작업
// 4. 링커

// ref
// (자료형)& (참조 이름) = (초기화);
// C++ 관점 : 해당 변수의 별명

// 어셈블리어 : 포인터와 동일

// 크기 : 32비트 환경 (4바이트) / 64비트 환경 (8바이트)

// ptr, ref 차이
// 1. 포인터는 중간에 대상을 변경할 수 있음 / ref는 중간에 대상을 변경할 수 없음
// 2. 포인터는 nullptr을 저장할 수 있음 / ref는 없는 값을 참조할 수 없음
// 3. 포인터는 초기화를 하지 않아도 됨 / ref는 초기화를 해야 함

// Call By Value
// 매개변수 Value만 읽기, 수정 가능함
// 원본을 수정할 수 없음 / 원본을 읽어오기(복사)는 가능

// Call By Address
// 매개변수 ptr에 타고 들어가서 읽기 / 수정 가능
// 원본을 수정할 수 있음
// 쓰기 어려움 (메모리 오염)

// Call By Reference
// 매개변수 ref(별명)에 가서 읽기 / 수정 가능
// 원본을 수정할 수 있음
// 쓰기 쉬움 (메모리 오염 걱정이 없음)

void AddOne(int* const ptr)
{
	(*ptr)++;
}

void AddOne(int& ref)
{
	ref++;
}

int main()
{
	int aInt = 1;
	int bInt = 2;

	int* ptr; //0xcccccccc
	int& ref = aInt;

	ref++;

	cout << ref << endl;

	AddOne(&aInt);

	cout << ref << endl;

	AddOne(aInt);

	return 0;
}
