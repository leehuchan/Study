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

		// 같은 길드 소속?
		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
			std::swap(uLeader, vLeader);

		// vLeader의 랭크가 항상 크거나 같음
		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader]);
		_rank[vLeader]++;

	}

	// 스패닝 트리(spanning Tree)
	// 모든 정점을 방문할 수 있는 간선의 집합
	// 사이클이 존재하면 안됨
	// 정점의 개수가 n일 때, n-1의 간선을 갖음
	
	// 최소스패닝 트리
	// 가중치 그래프에서 스패닝트리 중에 제일 작은 가중치를 갖는다.

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

	// 최소 간선부터 찾기 -> 정렬
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