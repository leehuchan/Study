#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adjacent;

class DisJointSet
{
public:
	DisJointSet(int n)
	{
		vector<vector<int>> adjacent;

		_parent = vector<int>(n, 0);
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
		_rank = vector<int>(n, 1);
	}

	int FindLearder(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];

		return FindLearder(parent);
	}

	void Merge(int u, int v)
	{
		int uLeader = FindLearder(u);
		int uLeader = FindLearder(v);

		// ���� ��� �Ҽ�?
		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
			std::swap(uLeader, vLeader);

		// vLeader�� ��ũ�� �׻� ũ�ų� ����
		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader]);
		_rank[vLeader]++;

	}

	// ���д� Ʈ��(spanning Tree)
	// ��� ������ �湮�� �� �ִ� ������ ����
	// ����Ŭ�� �����ϸ� �ȵ�
	// ������ ������ n�� ��, n-1�� ������ ����
	
	// �ּҽ��д� Ʈ��
	// ����ġ �׷������� ���д�Ʈ�� �߿� ���� ���� ����ġ�� ���´�.

	struct Edge
	{

		int u;
		int v;

		int cost;
	};

	void CreateEdge()
	{
		for (int u = 0; u < adjacent.size(); u++)
		{
			for (int v = 0; v < adjacent.size(); v++)
			{
				if (adjacent[u][v] < 0)
					continue;

				if (u >= v)
					continue;

				Edge edge;
				edge.u = u;
				edge.v = v;
				edge.cost = adjacent[u][v];
			}
		}

	}

private:
	vector<int> _parent;
	vector<int> _rank;
};



vector<Edge> Kruskal()
{
	vector<Edge> result;

	// �ּ� �������� ã�� -> ����
	std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge & ->b))-> bool
	{
		if (a.cost < b.cost)
			return true;
		return false;
	}
}

int main()
{
	CreateGraph();
	CreateEdges();

	for (auto edge : Mst)
	{

	}


	return 0;
}