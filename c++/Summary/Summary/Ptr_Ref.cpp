#include <iostream>

using namespace std;

struct Player
{
	// �������
	int hp;
	int atk;

};

// Call By Value
void PrintPlayer(Player p) // 8����Ʈ ����(int�� 2��)
{
	cout << p.hp << endl;
	cout << p.atk << endl;
}

void PrintPlayer(const Player* const ptr) // 4 ����Ʈ ����
{
	cout << (*ptr).hp << endl;
	cout << (*ptr).atk << endl;
}

void PrintPlayer(Player& p) // 4 ����Ʈ ����
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
	// . : ������ٿ�����
	player.hp = 1;
	player.atk = 2;

	Player* ptr = &player;
	Player& ref = player;

	int* ptr2 = &player.hp;

	PrintPlayer(&player);

	return 0;
}