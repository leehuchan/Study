#include <iostream>

using namespace std;

// (��ȯ �ڷ���) �Լ��̸�(�Ű�����) => �Լ� �ñ״�ó

// ������ ������
// *ptr : ���������� => �����Ͱ� ����ִ� �ּҰ����� ��ŻŸ�� ��
// &(����) : �ּҿ����� => ������ ����ִ� �ּҰ�

// Stack : ������ �ð��� ũ�Ⱑ ����

// ���� ������
// �޸��� ���� ������ ������� ����Ǵ� �Լ��� ȣ�� ����
// ��ȯ�ּҰ�, �Ű�����, ��������
// ������, ����

void HelloWorld()
{
	cout << "HelloWorld!" << endl;
}

// Call by Value
void AddOne(int num)
{
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3)), Add[��ȯ�ּҰ�(&aInt), �Ű�����(num : 3), �������� c()]
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(3)), Add[��ȯ�ּҰ�(&aInt), �Ű�����(num : 4), �������� c()]
	num++;
}

// Call by Address
void AddOne(int* ptr)
{
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(3)), Add[��ȯ�ּҰ�(&aInt), �Ű�����(ptr : 0x12), �������� c()]
	(*ptr)++;
	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������((0x12)aInt(4)), Add[��ȯ�ּҰ�(&aInt), �Ű�����(ptr : 0x12), �������� c()]

}

int Add(int a, int b)
{
	int c = a + b;

	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(cccccccc)), Add[��ȯ�ּҰ�(), �Ű�����(a 1, b 2), �������� c(3)]

	cout << c << endl;

	return c;
}

// �Լ� �����ε�
// �ٸ� ���� : �Ű������� �ڷ����̳� ������ �ٸ� ��
int Add(int a, int b, int c)
{
	int d = a + b + c;
	return d;
}

// �Լ� �Ű������� �⺻���� -> �Ű�����(����, parameter, arrgument)
// �⺻���ڴ� �� �ں��� �ʱ�ȭ�ؾ� ��
int Add(int a, int b, int c, int d, int e = 1)
{
	int f = a + b + c + d + e;
	return f;
}

// ���ȣ�� : ���ÿ����÷ο� => ���ÿ����� �� �̻� �Ҵ��� ���� ����.

int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}

// �޸������̼�
int cache[200] = {};

// �Ǻ���ġ ����
int Fibonacci(int num)
{
	if (num <= 1)
		return num;

	int* ref = &cache[num];
	if (*ref != 0)
		return *ref;

	*ref = Fibonacci(num - 1) + Fibonacci(num - 2);

	if (num == 2)
		cout << "Factorial 2 ���" << endl;

	// bhgreturn Fibonacci(num - 1) + Fibonacci(num - 2);
	return *ref;
}

int main()
{
	// HelloWorld();

	// main[��ȯ�ּҰ�(), �Ű�����(void), ��������(aInt(cccccccc))

	int aInt = Add(1, 2);
	// aInt ... 3

	AddOne(aInt);

	cout << aInt << endl;
	// aInt 3���� ���


	AddOne(&aInt);

	cout << aInt << endl;
	// aInt 4���� ���

	int bInt = Add(1, 2, 3, 4);

	cout << bInt << endl;

	int cInt = Factorial(5);

	cout << cInt << endl;

	int dInt = Fibonacci(20);

	cout << dInt << endl;

	return 0;
}