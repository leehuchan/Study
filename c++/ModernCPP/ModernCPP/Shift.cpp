#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

// ������(l-value), ������(r-value)

// l-value
// - ��������
// - ��ǥ���� ��) ����

// r-value
// l-value�� �ƴ� ��
// -���� �Ұ���
// - ��ǥ���� ��) const, ���

// shift : �̵�
// (�ڷ���)&& : ������ ���� -> C++11���� ��������� �̲������

class Pet
{
};

class Player
{
public:
	Player() { pet = new Pet(); } // �⺻ ������
	Player(int hp) { pet = new Pet(); } // Ÿ�� ��ȯ ������
	Player(const Player& other) // ���� ������
	{
		// ���� ����
		this->pet = new Pet(*other.pet);
	} 

	// ���� �� ����
	// 1. ������ ���� ����
	// 2. other�� ���������� ������ ���� -> �����⸸ ����ڴ�.
	// �Ű����� other�� �ӽð�ó�� ����ϰڴ�.
	Player(Player&& other) noexcept // �̵�������
	{
		cout << "�̵������� ȣ��" << endl;
		this->pet = other.pet;
		other.pet = nullptr;
	}
	~Player() 
	{
		if (pet != nullptr)
		{
			delete pet;
		}
	}

private:
	Pet* pet;
};

int main()
{
	const int temp = 1;

	int aInt = 1;
	aInt = 5;

	int& ref = aInt;
	ref = 3223;

	// player1���� player2�� �̻�
	Player* player1 = new Player();
	// Player* player2 = new Player(static_cast<Player&&>(*player1)); // �̵������� ȣ��
	Player* player2 = new Player(std::move(*player1)); // �̵������� ȣ��

	//vector<Player> players;
	//players.emplace_back(Player()); // players[0]


	delete player2;
	delete player1;

	return 0;
}