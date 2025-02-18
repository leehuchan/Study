#include <iostream>
#include <vector>

using namespace std;

// DP 방식
// 상향식
// 하향식
// 윈도우 방식

// 백준 2579번 계단 오르기

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

int DP(int n) // 하향식
{
	// 기저사항
	if (n < 0)
		return 0;

	// 메모이제이션
	int& ref = cache[n];
	if (ref != -1)
		return ref;

	// 구하기

	// 한 칸
	if (n > 0)
		ref = v[n] + v[n - 1] + DP(n - 3);

	// 두 칸
	ref = max(ref, v[n] + DP(n - 2));

	return ref;
}

int main()
{
	Input();

	cout << DP(v.size() - 1) << endl;

	return 0;
}