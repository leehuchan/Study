#include <iostream>

using namespace std;

struct Player
{
	// 멤버변수
	int hp;
	int atk;

};

// Call By Value
void PrintPlayer(Player p) // 8바이트 전달(int형 2개)
{
	cout << p.hp << endl;
	cout << p.atk << endl;
}

void PrintPlayer(const Player* const ptr) // 4 바이트 전달
{
	cout << (*ptr).hp << endl;
	cout << (*ptr).atk << endl;
}

void PrintPlayer(Player& p) // 4 바이트 전달
{
	cout << p.hp << endl;
	cout << p.atk << endl;
}

void SetPlayer(Player* p, int hp, int atk)
{
	(*p).hp = hp;
	(*p).atk = atk;
}

int main()
{
	Player player;
	// . : 멤버접근연산자
	player.hp = 1;
	player.atk = 2;

	Player* ptr = &player;
	Player& ref = player;

	int* ptr2 = &player.hp;

	PrintPlayer(&player);

	return 0;
}