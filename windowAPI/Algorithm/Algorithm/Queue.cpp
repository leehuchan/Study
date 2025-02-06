#include <iostream>
#include <list>
#include <queue>
#include <deque>

using namespace std;

// 큐 (Queue)
// 데이터를 선입선출 (FIFO, First-In-First-Out) 방식으로 관리하는 자료구조

template <typename T, typename Container = list<T>>
class Queue
{
public:
	void push(T value)
	{
		l.push_back(value);
	}
	void pop ()
	{
		l.pop_front();
	}
	T front()
	{
		return l.front();
	}
	bool empty()
	{
		return l.empty();
	}
private:
	Container l;
};

int main()
{
	// queue<int> q;
	Queue<int> q;

	q.push(10);
	q.push(7);
	q.push(15);
	q.push(1);
	q.push(3);

	while (true)
	{
		if (q.empty() == true)
			break;

		cout << q.front() << endl;
		q.pop();
	}
	
	return 0;
}