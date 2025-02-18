#include <iostream>
#include <vector>

using namespace std;

// LIS (���� �κ� ���� ����)

int cache[1001];

int LIS(int n, vector<int>& v)
{
	// ��������
	if (n == v.size() - 1)
		return v[n];

	// �޸������̼�
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// ���ϱ�
	ref = v[n];
	for (int next = n + 1; next < v.size(); next++)
	{
		if (v[n] <= v[next])
			ref = std::max(ref, LIS(next, v) + v[n]);
	}

	return ref;
}

int main()
{
	vector<int> v = { 5, 6, 7, 1, 2, 3, 4};

	int answer = 0;

	for (int i = 0; i < 1001; i++)
	{
		cache[i] = -1;
	}

	cout << LIS(0, v) << endl;

	for (int i = 0; i < v.size(); i++)
	{
		answer = std::max(answer, LIS(i, v));
	}

	cout << answer << endl;

	return 0;
}