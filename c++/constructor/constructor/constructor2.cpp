#include <iostream>

using namespace std;

class Player
{
public:
	Player() : _hp(0), _atk(0) { cout << "�⺻������ ȣ��" << endl; }
	Player(int hp) : _hp(0), _atk(0) { cout << "Ÿ�� ��ȯ ������ ȣ��" << endl; }

	// �Ҹ��� ����
	// 1. �����Ҵ� ����
	// 2. �Ҹ�ó��
	~Player() { cout << "�Ҹ��� ȣ��" << endl; }

protected:
	int _hp;
	int _atk;
};

class Knight : public Player
{

public:
	Knight() { cout << "Knight �⺻������ ȣ��" << endl; }
	// �����ʱ�ȭ �������� �θ��� �����ڸ� �Ͻ������� ȣ���Ѵ�.
	// ��������� ���� ȣ������ ���� �ִ�.

	~Knight() { cout << "Knight �Ҹ��� ȣ��" << endl; }
};


int main()
{
	// Player p(50);

	Knight k;
	// �θ������ ȣ�� -> �ڽ� ������ ȣ�� -> �ڽ� �Ҹ��� ȣ�� -> �θ� �Ҹ��� ȣ��

	return 0;
}