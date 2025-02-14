#include <iostream>
#include <vector>

using namespace std;

// 재련하기
// 강화를 하는데 +1, +2, +3
// n강을 할때 나올 수 있는 경우의 수
// 0 < n < 3000

vector<int> cache1 = vector<int>(3001, -1);
int Enchant(int n)
{
	// 하향식
	if (n == 0 || n == 1)
		return 1;
	if (n < 0)
		return 0;

	int& ref = cache1[n];
	if (ref != -1)
		return ref;

	return Enchant(n - 1) + Enchant(n - 2) + Enchant(n - 3);
}

int main()
{
	cout << Enchant(3) << endl;

	return 0;
}