#include <iostream>

using namespace std;

// 메모리 4영역
// code - 사람이 적는 코드
// data - 전역변수, 정적변수
// stack - [지역변수 매개변수 반환 주소값 -> 스택 프레임]
// - 생성 주기 : 함수 호출되었을 때 할당 / 함수 종료시 해제
// heap : 사용자가 직접 제어하는 메모리

int aInt = 1;

// 동적할당 -> HEAP 영역에 메모리를 할당하는 작업
// - 운영체제가 도와주는 작업(kernel 영역)

// kernel - 운영체제 중 항상 메모리에 올라가 있는 운영체제의 핵심 부분으로써 하드웨어와 응용 프로그램 사이에서 인터페이스를 제공하는 역할을 하며컴퓨터 자원들을 관리하는 역할
// 항상 컴퓨터 자원들을 바라만 보고 있기에 사용자와의 상호작용은 지원하지 않는다. 따라서 사용자와의 직접전인 상호작용을 위해 프로그램을 제공하게 되는데, 대표적으로 쉘(Shell)이라는 명령어 해석기가 있음


// malloc / free => C스타일
// // new / delete => C++스타일
// new[] / delete[]

// void* ?
// 타고 들어가면 void(정해지지 않았다.) => 무엇이든 올 수 있다.
// 모든 자료형을 가리킬 수 있음

class Player
{
public:
	Player(int hp, int atk) : _hp(hp), _atk(atk) { cout << "Player 생성" << endl; }
	~Player() { cout << "Player 소멸" << endl; }

private:
	int _hp;
	int _atk;
};

int main()
{
#pragma region Malloc/Free
	void* ptr = malloc(100);
	int* temp = (int*)ptr;

	for (int i = 0; i < 25; i++)
	{
		*(temp + i) = i;
	}

	for (int i = 0; i < 25; i++)
	{
		// cout << *(temp + i) << endl;

	}

	free(ptr);
#pragma endregion

	int* temp3 = new int(); // Heap에 4바이트만큼 동적할당
	int* temp4 = new int[25]; // Heap에 100바이트

	Player* p = new Player(100, 10);

	delete p;
	delete[] temp4;
	delete temp3;

	return 0;
}