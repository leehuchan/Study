#include <iostream>

// 상수
// 1. const
// 2. 매크로 (#define)
// 3. 열거형 (enum)

// 매크로
#define STUN 1
#define SUBDUE 1

// 열거형
enum state
{
	// 양의 정수
	State_STUN,
	State_SUBDUE,
	State_SLEEP

};

int main()
{
	const int temp = 1;

	return 0;
}