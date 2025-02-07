#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// �׷���
// Vertex�� edge�� �̷���� �ڷᱸ��

// adjacent : ����

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

vector<vector<bool>> adjacent; // �������
// �����͸� ���� �ʿ�������� Ž���ϴµ� ����� �ð��� �ɸ���.
void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(false, 7)); // 7X7 ���
	// adjacent.resize(7, vector<bool>(7, false)); // ���� �ڵ�� ����

	// ����� �׷��� A�� A�� ��ġ���(A)�� ���� ����
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
	// 0�� 2�� ���� ������ �Ǿ��ִ°�?
	auto iter = std::find(adjacent_list[0].begin(), adjacent_list[0].end(), 2);

	if (iter != adjacent_list[0].end())
		cout << *iter << endl;

	// 0�� 2�� ���� ����Ǿ��ִ°�?
	if (adjacent[0][2]) // ����� �ð�
	{
		cout << "0�� 2�� ����Ǿ��ֽ��ϴ�." << endl;
	}

	return 0;
}