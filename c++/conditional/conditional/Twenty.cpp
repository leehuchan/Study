#include <iostream>

using namespace std;

// 스무고개
// 1. 1~500의 숫자를 컴퓨터가 가지고있음.
// 2. 플레이어가 수를 입력함
// 3. 이를 9번 반복으로 수를 

int main()
{
	srand(time(NULL));

	int computerNum = rand() % 500 + 1;

	for (int i = 0; i < 9; i++)
	{
		cout << "숫자를 입력하세요" << endl;
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
			cout << "정답입니다." << endl;
			break;
		}
	}

	return 0;
}