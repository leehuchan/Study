#include <iostream>

using namespace std;

// ������
// 1. 1~500�� ���ڸ� ��ǻ�Ͱ� ����������.
// 2. �÷��̾ ���� �Է���
// 3. �̸� 9�� �ݺ����� ���� 

int main()
{
	srand(time(NULL));

	int computerNum = rand() % 500 + 1;

	for (int i = 0; i < 9; i++)
	{
		cout << "���ڸ� �Է��ϼ���" << endl;
		int playerNum = 0;
		cin >> playerNum;

		if (computerNum > playerNum)
		{
			cout << "UP" << endl;
		}
		else if (computerNum < playerNum)
		{
			cout << "DOWN" << endl;
		}
		else
		{
			cout << "�����Դϴ�." << endl;
			break;
		}
	}

	return 0;
}