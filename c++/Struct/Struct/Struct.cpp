#include <iostream>

using namespace std;

// . : 멤버 접근연산자
// -> : 간접멤버접근연산자

struct Player
{
	// 멤버 변수
	string name;
	int hp;
	int atk;
};

// 상수로 선언해서 포인터의 읽기 전용으로 만들 수 있음

// Call By Value 단점
// 원본에 접근할 수 없다.
// 매개변수로 생성하는 바이트가 크다.

/*
void PrintPlayer(Player p)
{
	cout << "NAME : " << p.name << endl;
	cout << "HP :" << p.hp << endl;
	cout << "ATK : " << p.atk << endl;
}
*/

// Call By Address
// 장점
// 원본에 접근할 수 있다.
// nullptr을 담을 수 있다.

// 단점
// 유효성 체크를 해야 한다.
void PrintPlayer(const Player* const p)
{
	if (p == nullptr) return;

	cout << "NAME : " << p->name << endl;
	cout << "HP :" << p->hp << endl;
	cout << "ATK : " << p->atk << endl;
}

// Call By Reference
// 장점
// 원본에 접근할 수 있다.
// 쓰기 쉽다.

// 단점
// Call By value와 구분할 수 없다.
void PrintPlayer(const Player& p) // -> C++ Read Only
{
	cout << "NAME : " << p.name << endl;
	cout << "HP :" << p.hp << endl;
	cout << "ATK : " << p.atk << endl;
}

void SetPlayer(Player* p, string name, int hp, int atk)
{
	p->name = name;
	(*p).hp = hp; // (*p).hp와 p->는 같다.
	(*p).atk = atk;
}

void SetPlayer(Player& p, const string& name, int hp, int atk)
{
	p.name = name;
	p.hp = hp;
	p.atk = atk;
}

void Attack(Player* attacker, Player* victim)
{
	victim->hp -= attacker->atk;
	cout << attacker->name << "이 " << victim->name << "을 " << attacker->atk << "만큼 공격했습니다!!" << endl;
}

int main()
{
	Player p1;
	p1.hp = 0;
	p1.atk = 0;

	Player p2;
	p2.hp = 0;
	p2.atk = 0;

	SetPlayer(&p1, "Huchan1", 100, 25);
	SetPlayer(&p2, "Huchan2", 150, 13);

	cout << "플레이어 1 " << endl;
	PrintPlayer(&p1);
	cout << endl;
	cout << "플레이어 2 " << endl;
	PrintPlayer(&p2);
	cout << endl;

	while (true)
	{
		Attack(&p1, &p2);
		cout << "현재 플레이어 p2의 체력 : " << p2.hp << endl;
		if (p2.hp <= 0)
		{
			cout << "플레이어 2가 패배하였습니다." << endl;
			break;
		}
		Attack(&p2, &p1);
		cout << "현재 플레이어 p1의 체력 : " << p1.hp << endl;
		if (p1.hp <= 0)
		{
			cout << "플레이어 1이 패배하였습니다." << endl;
			break;
		}
	}

	return 0;
}