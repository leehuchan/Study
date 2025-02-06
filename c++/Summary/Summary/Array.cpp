#include <iostream>

using namespace std;

// 1. ��� ������ 3����
// ����� ���ÿ� �ʱ�ȭ
// #define ��ũ��
// const
// enum

// 2. ������ ����

// 3. �迭, �迭�� �������� �������

#define PI 3.141592f
#define Declare(k) float temp(k)

// ������ ���
// ������
enum PlayerState
{
	IDLE = 5,
	RUN,
	FALLING,
	SLEEPING
};

// ������
// (�ڷ���)* (�����̸�): ������ ����
// (����) * (����) : ����������
// *(����) : ����������
// (�ڷ���)** (�����̸�): ����������

// (����) & (����) : ��Ʈ And������
// (����) && (����) : And ������
// (�ڷ���)& (�����̸�) = �ʱ�ȭ : Reference ����
// &(����) : �ּҿ�����

// ������ ������
// (ptr + 1) => �������� �ڷ����� ����

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void PrintArr(int arr[][3], int size)
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << arr[y][x] << endl;
		}
	}
}

int main()
{
	// const(�ڷ���) : ��� ��� => ���� �Ұ���
	const int temp = 1;

	PlayerState curState = PlayerState::IDLE;

	// const (�ڷ���)* const : �б� ����
	const int* ptr = &temp;

	// const �ڷ���& : �б� ����
	const int& ref = temp;

	int aInt = 1;
	int* ptr2 = &aInt;

	cout << (ptr2) << endl;

	cout << (ptr2) << endl;

	cout << (ptr2 + 1) << endl;

	int arr[10]; // �����迭
	// [index] : �������ٿ�����
	// �迭�� ���������ϴµ� �ɸ��� �ð����⵵�� ���

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	ptr2 = &arr[0];

	PrintArr(&arr[0], 10);

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << *(ptr2 + i) << endl;
	//	cout << ptr2[i] << endl;
	//	cout << arr[i] << endl;
	//}
	


	return 0;
}