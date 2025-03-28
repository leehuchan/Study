﻿#include <iostream>

using namespace std;

// 포인터 (자료형)
// 주소값
// (자료형)* 변수이름 = 초기화;

// 크기 : 32비트 환경 4바이트
//        64비트 환경 8바이트

// &(변수) : 해당 변수의 주소값을 반환 -> 주소연산자
// *(변수) : 포인터가 가지고있는 주소값을 타고 들어갔을 때, 그 값을 반환 -> 간접연산자


// (자료형)이 필요한 이유?
// 힌트, 타고 들어갔을 때 (자료형)인 변수가 있어야한다.

// Call by Value
// 매개변수에 값을 복사

// Call by Address
// 매개변수에 주소값을 복사

void AddOne(int* a)
{
	++*a;
}

int main()
{
	int aInt = 1;

	int* aPtr = &aInt;


	cout << aPtr << endl;
	cout << *aPtr << endl;

	AddOne(&aInt);

	cout << aInt << endl;

	return 0;
}

// 과제
// 1. 포인터와 참조에 대해서 비교
// 참조는 단독으로 정의하지 못한다. (포인터는 단독정의가 가능)
// 포인터는 정의와 동시에 그에 맞는 메모리가 할당되지만, 참조는 메모리를 차지하지 않는 경우도 있다.
// 참조는 일단 정의하면 가리키는 변수를 바꿀 수 없다. 포인터는 가리키는 변수를 바꿀 수 있다.
// null 값을 저장할 수 있는 포인터와 다르게, null 참조 같은 것은 없다.
// 
// 참조
// 참조형은 선언과 동시에 반드시 초기화해야 한다.
// 참조형은 함수 매개 변수로 가장 많이 사용된다. 이때 매개 변수는 인수의 별칭으로 사용된다.
// 참조 매개 변수를 사용하는 함수는 전달된 인수를 수정할 수 있다.
// 참조형은 중첩된 데이터에 쉽게 접근할 수 있다
// 참조의 참조, 참조의 배열, 참조의 포인터는 존재하지 않는다.
// 
// 2. 포인터 연산자
// 대입 연산자 왼쪽에서 포인터 연산자는 포인터를 선언하는데 쓰이며, 대입 연산자 오른쪽에서 사용되는 포인터 연산자는 주소에 있는 값을 의미한다.
// 
// 3. 배열(Array)
// 단일 식별자를 통해 같은 자료형의 여러 변수에 접근할 수 있게 해주는 집계 데이터 유형이다.
// 대괄호 []를 사용해서 컴파일러에 배열 변수와 할당할 변수 수를 지정할 수 있습니다.
// 모든 자료형의 배열을 만들 수 있으며, 구조체도 배열로 만들 수 있습니다
// 구조체 멤버에 접근하려면 먼저 원하는 배열 요소를 선택한 다음 멤버 선택 연산자(.)를 사용해서 원하는 멤버를 선택합니다.
// 배열에 있는 각 변수를 요소(element)라고 하며, 요소에는 고유한 이름이 없습니다.
// 배열의 개별 요소에 접근하려면 '배열이름 [인덱스]' 이러한 방식으로 접근합니다.