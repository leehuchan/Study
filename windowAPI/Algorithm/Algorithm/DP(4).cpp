#include <iostream>
#include <vector>

using namespace std;

// LIS (최장 부분 증가 수열)

int cache[1001];

int LIS(int n, vector<int>& v)
{
	// 기저사항
	if (n == v.size() - 1)
		return v[n];

	// 메모이제이션
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// 구하기
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