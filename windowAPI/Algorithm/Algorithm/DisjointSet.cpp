#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct User
{
	int guildId = 0;

	// hp...
};

void GuildSystem()
{
	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		users.push_back({ i });
	}

	/// 555��° ������, 1�� ° ���� ��忡 ����
	users[555].guildId = users[1].guildId;

	// guild Id�� 2�� �������� 1��忡 ���� ->N��ŭ�� �ð����⵵

	for (auto& user : users)
	{
		if (user.guildId == 2)
		{
			user.guildId = 1;
		}
	}

}

class DisJointSet
{
public:
	DisJointSet(int n)
	{
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

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{


	return 0;
}