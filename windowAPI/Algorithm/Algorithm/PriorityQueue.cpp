#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// �켱���� ť
// 1. ��������Ʈ��
// 2. ���̷� (�ִ���, �ּ���)

template <typename T, typename Container = vector<T>, typename Pred = less<int>>
class PriorityQueue
{
public:
	// ���� �غ����� ��
	//void push(T value)
	//{
	//	if (v.empty())
	//	{
	//		v.push_back(value);
	//	}
	//	else
	//	{
	// v.push_back(value);
	//		while (true)
	//		{
	//			if (value > v.back())
	//			{
	//				Swap(value, v.back());
	//			}
	//		}
	//		for (int i = 0; i < v.capacity(); i++)
	//		{

	//		}
	//	}
	//}

	void push(T value)
	{
		v.push_back(value);

		int now = v.size() - 1;

		while (true)
		{
			if (now <= 0)
				break;

			int parent = (now - 1) / 2;

			if (pred(v[now], v[parent]))
				break;

				std::swap(v[parent], v[now]);
				now = parent;
		}
	}


	bool empty()
	{
		return v.empty();
	}

	T top()
	{
		return v[0];
	}

	void pop()
	{
		swap(v.back(), v.front());
		v.pop_back();

		int now = 0;

		while (true)
		{
			int left = now * 2 + 1;
			int right = now * 2 + 2;

			// left�� ���� -> ��Ʈ ��常 ����
			if (left >= v.size())
			{
				break;
			}

			int next = now;

			if (pred(v[next], v[left]))
			{
				next = left;
			}

			if (right < v.size() && pred (v[next], v[right]))
			{
				next = right;
			}
			
			// now.. left, right �߿� ���� ū ��

			if (next == now)
				break;

			std::swap(v[next], v[now]);

			now = next;
		}
	}


private:
	Container v;
	Pred pred;
};

template<typename T>
struct Less
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

int main()
{
	// �ִ���
	// priority_queue<int> pq;
	PriorityQueue<int> pq;
	pq.push(100);
	pq.push(80);
	pq.push(70);
	pq.push(50);
	pq.push(75);

	while (true)
	{
		if (pq.empty())
			break;

		int top = pq.top();
		cout << top << endl;
		pq.pop();
	}

	return 0;
}