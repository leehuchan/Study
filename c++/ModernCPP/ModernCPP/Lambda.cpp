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
	// 람다 : 무명함수
	vector<Player*> players;

	for (int i = 0; i < 10; i++)
	{
		Player* p = new Player();
		p->_pet = new Pet();
		p->_pet->_atk = rand() % 50;

		players.push_back(p);
	}

	// players 배열을 정렬한건데 player 한 명이 갖고있는 pet의 데미지에 따라서 players를 정렬하라

	bool myfunctionSort();

	SortComparer fuctor;

	// sort(players.begin(), players.end(), &ComparePlayer); -> 함수 포인터
	// sort(players.begin(), players.end(), SortComparer()); -> 함수 객체
	// sort(players.begin(), players.end(), fuctor); // -> 함수 객체

	vector<int> v = { 1,25,6,23,4,5 };

	// 람다식
	// [캡처](매개변수) -> (반환형식) { 함수 정의부 }
	// [캡처] : 람다식 외부의 변수를 캡처하는 용도

	// 20보다 큰 수의 개수
	int compareNum = 20;

	int c = std::count_if(v.begin(), v.end(), [&compareNum](const int& element) -> bool
		{
			if (element > compareNum)
				return true;
			return false;
		});

	cout << c << endl;

	// 25보다 큰 수의 개수
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

	// 함수 포인터, (함수 객체, 람다) Callable 객체
	// Callable 객체를 매개변수로 넘기는 것을 '콜백함수' -> Delegate
	function<void(void)> fn; // fn은 함수 포인터, 함수 객체, 람다
	fn = []() {};

std::sort(players.begin(), players.end(), [](Player* left, Player* right)->bool
	{
		if (left->_pet->_atk < right->_pet->_atk)
			return true;
		return false;
	});

return 0;
}