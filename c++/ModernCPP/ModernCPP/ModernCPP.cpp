#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

// ModernCPP
// C++ 11
// auto
// = 무조건 초기화
// 남발하면 가독성이 떨어짐

// using

// 중괄호 초기화, 초기화 리스트

// Deque
// 람다
// std::move
// 스마포인터

typedef void(*Func1)(void);
using Func2 = void(*)(void);

struct Vector
{
	Vector() = default;

	float x = 10;
	float y = 2;
};

class Pet;
class Player
{
	friend Pet;
private:
	int _hp;
	int _akt;
};

class Pet
{

};

int main()
{
	unordered_map<int, int> um;
	auto iter = um.begin();
	auto aInt = 1;

	Func1 func;
	Func2 func2;

	int arr[3] = { 1,2,3 };
	int bInt = { 123 };
	Vector v = { 1.1f, 2.5f };

	// 범위기반 for문
	vector<int> myV = { 4,1,3,4,2,3,10,124,3 };

	for (auto& element : myV)
	{
		cout << element << endl;
	}

	// Tuple : 세 가지 이상
	tuple<int, float, int, string> p;

	string str = "Hello"; // 맨 뒤에 있는 비트가 '0'




	return 0;
}