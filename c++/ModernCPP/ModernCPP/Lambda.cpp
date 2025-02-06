#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

class Pet
{
public:
	int _atk;
};

class Player
{
public:
	int _hp = 0;
	int _atk = 0;

	Pet* _pet = 0;
};

bool ComparePlayer(Player* left, Player* right)
{
	if (left->_pet->_atk < right->_pet->_atk)
		return true;
	return false;
}

struct SortComparer
{
	bool operator()(Player* left, Player* right)
	{
		if (left->_pet->_atk < right->_pet->_atk)
			return true;
		return false;
	}
};

int main()
{
	// ���� : �����Լ�
	vector<Player*> players;

	for (int i = 0; i < 10; i++)
	{
		Player* p = new Player();
		p->_pet = new Pet();
		p->_pet->_atk = rand() % 50;

		players.push_back(p);
	}

	// players �迭�� �����Ѱǵ� player �� ���� �����ִ� pet�� �������� ���� players�� �����϶�

	bool myfunctionSort();

	SortComparer fuctor;

	// sort(players.begin(), players.end(), &ComparePlayer); -> �Լ� ������
	// sort(players.begin(), players.end(), SortComparer()); -> �Լ� ��ü
	// sort(players.begin(), players.end(), fuctor); // -> �Լ� ��ü

	vector<int> v = { 1,25,6,23,4,5 };

	// ���ٽ�
	// [ĸó](�Ű�����) -> (��ȯ����) { �Լ� ���Ǻ� }
	// [ĸó] : ���ٽ� �ܺ��� ������ ĸó�ϴ� �뵵

	// 20���� ū ���� ����
	int compareNum = 20;

	int c = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});

	cout << c << endl;

	// 25���� ū ���� ����
	compareNum = 25;

	int d = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});

	cout << d << endl;

	std::for_each(v.begin(), v.end(), [](const int& element)->void
		{
			cout << "HelloWorld!" << endl;
		}
	);

	// �Լ� ������, (�Լ� ��ü, ����) Callable ��ü
	// Callable ��ü�� �Ű������� �ѱ�� ���� '�ݹ��Լ�' -> Delegate
	function<void(void)> fn; // fn�� �Լ� ������, �Լ� ��ü, ����
	fn = []() {};

std::sort(players.begin(), players.end(), [](Player* left, Player* right)->bool
	{
		if (left->_pet->_atk < right->_pet->_atk)
			return true;
		return false;
	});

return 0;
}