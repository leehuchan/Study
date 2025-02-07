#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// 그래프
// Vertex아 edge로 이루어진 자료구조

// adjacent : 인접

vector<vector<int>> adjacent_list;
void CreateGraph_list()
{
	adjacent_list.resize(7);
	adjacent_list[0] = { 0,1,2,3 };
	adjacent_list[1] = { 0,1,4 };
	adjacent_list[2] = { 0,2,5,6 };
	adjacent_list[3] = { 0,3 };
	adjacent_list[4] = { 1,4 };
	adjacent_list[5] = { 2,5 };
	adjacent[6] = { 2,6 };

}

vector<vector<bool>> adjacent; // 인접행렬
// 데이터를 많이 필요로하지만 탐색하는데 상수의 시간이 걸린다.
void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(false, 7)); // 7X7 행렬
	// adjacent.resize(7, vector<bool>(7, false)); // 위쪽 코드와 동일

	// 양방향 그래프 A는 A와 전치행렬(A)와 서로 같음
	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][3] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][4] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][5] = true;
	adjacent[2][6] = true;

	adjacent[3][0] = true;
	adjacent[3][3] = true;

	adjacent[4][1] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

}

int main()
{
	CreateGraph_list();
	// 0과 2가 현재 연결이 되어있는가?
	auto iter = std::find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	if (iter != adjacent_list[0].end())
		cout << *iter << endl;

	// 0과 2가 현재 연결되어있는가?
	if (adjacent[0][2]) // 상수의 시간
	{
		cout << "0과 2가 연결되어있습니다." << endl;
	}

	return 0;
}