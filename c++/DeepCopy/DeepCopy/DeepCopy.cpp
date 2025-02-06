#include <iostream>

using namespace std;

class Pet
{
public:

private:
	int _hp;
	//
};

class Player
{
public:
	Player()
	:_pet(new Pet())
	{
		cout << "Player 생성자" << endl;
	}

	~Player()
	{
		if (_pet == nullptr) return;

		delete _pet;
	}

	// 얕은 복사 => 깊은 복사
	// 깊은 복사 : 동적할당되어있는 멤버변수를 복사해서 새로운 객체를 만드는 작업

	Player(const Player& p)
	:_pet(new Pet(*p._pet))
	{
		cout << "복사 대입 생성자 호출" << endl;
	}

	Player& operator=(const Player& other)
	{
		cout << "대입 연산자 호출" << endl;
		_pet = new Pet(*other._pet);

		return *this;
	}

private:
	// 내부에서 동적할당
	Pet* _pet;
};

int main()
{
	Player p;
	Player p2 = p;
	Player p3;

	p3 = p2;
	// 허상포인터
	// 지워진 곳(허상포인터)을 한번 더 지우려고하면서 커널 오류 발생

	return 0;
}