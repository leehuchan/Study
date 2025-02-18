#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> sumV;
int N;

int sum;
int answer;

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

int DP(int n, int t)
{
	for (int i : v)
	{
		sum += i;
		sumV.push_back(sum);
	}

	if (n==1)
	{
		answer = sumV[t - 1];
	}
	else
	{
		answer = sumV[t - 1] - sumV[n - 2];
	}

	return answer;
}

int main()
{
	v = { 5,4,3,2,1 };

	cout << DP(1,3) << endl;

	return 0;
}