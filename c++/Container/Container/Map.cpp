#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;

// map
// map은 각 노드가 key와 value 쌍으로 이루어진 트리입니다.
// 특히, 중복을 허용하지 않음, Key값으로 탐색에 용이함
// 내부 구현은 검색, 삽입, 삭제가 O(log2(n)) 인 레드블랙트리로 구성
// 레드블랙트리
// -> 자가균형이진탐색트리로써 삽입과 삭제가 일어나는 경우에 자동으로 그 높이를 작게 유지하는 이진 탐색 트리
// 높이를 작게 유지하는 이유는 연산 과정에서 트리의 높이가 한쪽으로 치우치는 것을 막기 위함
// Database 기본 Key에 사용, 클러스티드 인덱스

// unorderd_map (해시 테이블)
// map보다 더 빠른 탐색을 하기 위한 자료구조, Key값으로 탐색에 용이함
// unordered_map은 해시테이블로 구현한 자료구조로 탐색, 삽입, 삭제 시간복잡도는 O(1)
// unordered_map은 중복된 데이터를 허용하지 않고 map에 비해 데이터가 많을 시 월등히 좋은 성능을 보임
// key가 유사한 데이터가 많을 시 해시 충돌로 인해 성능이 떨어질 수도 있음 -> 체이닝으로 해결
// 게임, 넌클러스티드 인덱스

// 해싱 : 
// 체이닝 :

class Player
{
public:
	Player() {}
	Player(int id) : _id(id) {}

public:
	int _id;
};

int main()
{
	// Player를 ID로 구분해서 넣는 작업
	vector<Player> players;

	for (int i = 0; i < 1000; i++)
	{
		players.push_back(i + 1);
	}

	// id가 500인 플레이어를 찾고 싶다. -> vector 경우에 탐색시간 : 시간복잡도(N)
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]._id = 500)
		{
			// 찾음
		}
	}

	// -------------------------------------------------------------------------

	// map과 unordered_map과 사용 방법은 같음

	unordered_map<int, Player> um; // 해시 함수는 int, string을 많이 사용

	map<int, Player> m;

	for (int i = 0; i < 1000; i++)
	{
		um[ i + 1] = Player(i);
		//pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		//auto result = um.insert(pair); // 성공 여부를 알 수 있음
	}

	for (int i = 0; i < 100; i++)
	{
		m[i + 1] = Player(i);
		//pair<int, Player> pair = make_pair<int, Player>(i + 1, Player(i));
		//auto result = m.insert(pair); // 성공 여부를 알 수 있음
	}

	map<int, Player>::iterator m_iter;
	m.erase(1); // 맵 Key 1번 삭제

	for (m_iter = m.begin(); m_iter != m.end(); m_iter++)
	{
		pair<int, Player> p = *m_iter;
		cout << "Key : " << p.first << endl;
	}

	return 0;
}