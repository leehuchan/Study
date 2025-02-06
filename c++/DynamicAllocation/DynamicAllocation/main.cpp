#include <iostream>

using namespace std;

class Player
{
public:
	Player() : _hp(1) { cout << "Player 생성자" << endl; }
	virtual ~Player() { cout << "Player 소멸자" << endl; }

	virtual void Attack() { cout << "Player Attack!!!" << endl; }

protected:
	int _hp;
};

class Knight : public Player
{
public:
	Knight() : _atk(2) { cout << "Knight 생성자" << endl; }
	~Knight() { cout << "Knight 소멸자" << endl; }

	virtual void Attack() override { cout << "Knight Attack!!!" << endl; }

	// 가상함수
	// 가상함수를 선언하면 객체 맨 앞주소에 이상한(?)것이 생겼다.
	// -> 가상함수 테이블을 가리키는 포인터(vftable ptr)

	// 가상함수테이블(vftable)
	// 가상함수들을 갖고 있는 테이블
	// -> 실행시간에 어떤 함수를 호출해야되는지 알려준다.
	// -> 실행시간에 어떤 타입인지 확인할 수 있는 수단
	// -> RTTI(Run Time Type Information) // 면접 질문
	// -> 동적 바인딩

	// 정적 바인딩
	// 컴파일 타임에 호출될 함수가 결정되는 것으로, 함수는 기본적으로 정적 바인딩

private:
	int _atk;

};

int main()
{
	Player* k = new Knight();
	//업캐스팅 : 자식클래스로 생성된 객체를 부모의 포인터자료형으로 가리키는 것
	// 업캐스팅 쓰는 이유
	// 형변환을 통해 자료구조에 같이 묶어서 표현할 수 있음
	// 2. 매개변수에 단 한가지(최상위 부모)자료형으로 자식을 매개변수로 넘길 수 있음

	k->Attack(); // (Knight*) 없어도 중간에 타입이 무엇인지 확인할 수 있어야 한다.

	delete k;

	return 0;
}