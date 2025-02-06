#include <iostream> 
#include <vector>
#include <stack>

using namespace std;

// ���� (Stack)
// �����͸� ���Լ��� (LIFO, Last-In-First-Out) ������� �����ϴ� �ڷᱸ��

template <typename T, typename Container = vector<T>>
class Stack
{
public:
	void push(T value)
	{
		v.push_back(value);
	}
	void pop ()
	{
		v.pop_back();
	}

	T top()
	{
		return v.back();
	}
	bool empty()
	{
		return v.empty();
	}
private:
	Container v;

};

int main()
{
	// stack<int> s;

	Stack<int> s;

	s.push(10);
	s.push(1);
	s.push(15);
	s.push(6);
	s.push(100);

	while (true)
	{
		if (s.empty() == true)
			break;

		cout << s.top() << endl;
		s.pop();
	}
}