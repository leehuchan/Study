#include <iostream>
#include <list>
#include <queue>
#include <deque>

using namespace std;

// ť (Queue)
// �����͸� ���Լ��� (FIFO, First-In-First-Out) ������� �����ϴ� �ڷᱸ��

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