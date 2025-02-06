#include <iostream>

using namespace std;
// 부호가 없는 정수형으로 비트연산을 해야함 (음수가 나오는 것을 방지)

// 비트 연산
// &, |, ^, >>, <<
// & : 비트 and 연산
// | : 비트 or 연산
// ^ : 비트 xor 연산 => 둘 다 같으면 0, 다르면 1

// << : 좌측 시프트 연산
// 효과 : X2
// 맨 왼쪽 비트는 버려지게 된다.
// 오른쪽 비트는 0으로 채워짐
// 
// >> : 우측 시프트 연산
// 맨 오른쪽 비트는 버려지게 된다.
// 맨 왼쪽비트는 부호를 따르게 된다.

// 내가 무슨 cc기에걸렸는지 확인
unsigned char bitFlag = 0;
const unsigned char stun = 1;
const unsigned char subdue = (1 << 1);
const unsigned char sleep = (1 << 2);
const unsigned char transition = (1 << 3);



int main()
{
	// 기절, 수면
	bitFlag = subdue;

	// 기절에걸려있습니까?
	// & stun -> 비트마스크

	if (bitFlag & stun)
	{
		cout << "기절에 걸려있습니다." << endl;
	}

	// 제압에 걸리고, 기절이 풀림

	bitFlag |= subdue;
	bitFlag ^= stun;

	// 제압이고 변이상태인지 질문
	if ((bitFlag & subdue) && (subdue | transition))
	{
		cout << "제압이고 변이상태입니다." << endl;
	}

	return 0;
}