#include <iostream>

using namespace std;

class Player
{
public:
	Player() : _hp(1) { cout << "Player ������" << endl; }
	virtual ~Player() { cout << "Player �Ҹ���" << endl; }

	virtual void Attack() { cout << "Player Attack!!!" << endl; }

protected:
	int _hp;
};

class Knight : public Player
{
public:
	Knight() : _atk(2) { cout << "Knight ������" << endl; }
	~Knight() { cout << "Knight �Ҹ���" << endl; }

	virtual void Attack() override { cout << "Knight Attack!!!" << endl; }

	// �����Լ�
	// �����Լ��� �����ϸ� ��ü �� ���ּҿ� �̻���(?)���� �����.
	// -> �����Լ� ���̺��� ����Ű�� ������(vftable ptr)

	// �����Լ����̺�(vftable)
	// �����Լ����� ���� �ִ� ���̺�
	// -> ����ð��� � �Լ��� ȣ���ؾߵǴ��� �˷��ش�.
	// -> ����ð��� � Ÿ������ Ȯ���� �� �ִ� ����
	// -> RTTI(Run Time Type Information) // ���� ����
	// -> ���� ���ε�

	// ���� ���ε�
	// ������ Ÿ�ӿ� ȣ��� �Լ��� �����Ǵ� ������, �Լ��� �⺻������ ���� ���ε�

private:
	int _atk;

};

int main()
{
	Player* k = new Knight();
	//��ĳ���� : �ڽ�Ŭ������ ������ ��ü�� �θ��� �������ڷ������� ����Ű�� ��
	// ��ĳ���� ���� ����
	// ����ȯ�� ���� �ڷᱸ���� ���� ��� ǥ���� �� ����
	// 2. �Ű������� �� �Ѱ���(�ֻ��� �θ�)�ڷ������� �ڽ��� �Ű������� �ѱ� �� ����

	k->Attack(); // (Knight*) ��� �߰��� Ÿ���� �������� Ȯ���� �� �־�� �Ѵ�.

	delete k;

	return 0;
}