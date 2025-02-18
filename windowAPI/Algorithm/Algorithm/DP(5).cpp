#include <iostream>
#include <vector>

using namespace std;

// DP ���
// �����
// �����
// ������ ���

// ���� 2579�� ��� ������

vector<int> v;
int N;

int cache[301];

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

int DP(int n) // �����
{
	// ��������
	if (n < 0)
		return 0;

	// �޸������̼�
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// ���ϱ�

	// �� ĭ
	if (n > 0)
		ref = v[n] + v[n - 1] + DP(n - 3);

	// �� ĭ
	ref = max(ref, v[n] + DP(n - 2));

	return ref;
}

int main()
{
	Input();

	cout << DP(v.size() - 1) << endl;

	return 0;
}