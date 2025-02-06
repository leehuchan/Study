#include <iostream>

using namespace std;

/*
�Լ�
// �Ű������� �ְ� ��ȯ�� �޴� ��

�Լ� �ñ״�ó
(��ȯ�ڷ���) �Լ��̸� (�Ű�����);

*/

// Stack ����
// ��������
// �Ű�����
// ��ȯ�ּ� ��

// ���� ������
/*
�Լ��� ȣ��Ǹ� ���ÿ��� �Լ��� �Ű�����, ȣ���� ���� �� ���ư� ��ȯ �ּҰ�, �Լ����� ����� ���� ���� ���� ����˴ϴ�.

�̷��� ���� ������ ���ʴ�� ����Ǵ� �Լ��� ȣ�� ������ ���� ������(stack frame)�̶�� �մϴ�.

�̷��� ���� ������ ���п� �Լ��� ȣ���� ��� ���� �ڿ�, �ش� �Լ��� ȣ��Ǳ� ���� ���·� �ǵ��ư� �� �ֽ��ϴ�.
*/
// FIFO

void HelloWorld(int temp)
{
	cout << "Hello World" << temp << endl;
}
// Call By Value
int Add(int a, int b)
{
	int c = a + b;
	// main[��ȯ�ּ� ��, ���� ����(aInt(1), bInt(2)), �Ű�����()] ADD[��ȯ�ּҰ�, ��������(c(3)), �Ű�����(a(1),b(2))]

	cout << c << endl;

	return c;
}

// �Լ� �����ε�
// �Լ� �̸��� ����, �Ű������� �ڷ����̳� ������ �ٸ� ��

int Add(int a, int b, int c)
{
	int d = Add(a, b) + c;

	cout << d << endl;

	return d;
}

// �⺻����
// �� ���� ���ں��� ���� ������Ѵ�.
int Add(int a, int b, int c, int d, int e = 4)
{
	int f = Add(a,b,c) + d + e;

	cout << f << endl;

	return f;
}

/*
int Add(int a, int b, int c, int d)
{
	int f = a + b + c + d;

	cout << f << endl;

	return 0;
}
*/

// ���ȣ�� : �Լ��� �ڱ� �ڽ��� ȣ��

int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);

}


int main()
{
	int aInt = 1;
	int bInt = 2;
	int cInt = 3;
	int dInt = 4;
	int eInt = 5;


	// main[��ȯ�ּ� ��, ���� ����(aInt(1), bInt(2)), �Ű�����()]
	if (Add(aInt, bInt, cInt, dInt) == 14)
	{
		cout << "14 �Դϴ�." << endl;
	}

	cout << Factorial(5) << endl;

	return 0;
}