#include <iostream>
#include <vector>

using namespace std;

// ���� 2579�� ��� ������

vector<int> v;
int N;

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		v.push_back(temp);
	}
}



int main()
{
	Input();

	// cout <<  << endl;

	return 0;
}