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

	/// 555번째 유저가, 1번 째 유저 길드에 병합
	users[555].guildId = users[1].guildId;

	// guild Id가 2인 유저들이 1길드에 통합 ->N만큼의 시간복잡도

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

private:
	vector<int> _parent;
	vector<int> _rank;
};

int main()
{


	return 0;
}