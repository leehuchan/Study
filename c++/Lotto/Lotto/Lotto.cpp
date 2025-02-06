#include <iostream>
#include <time.h>

using namespace std;

// 1 ~ 45의 숫자 중에서 중복없이 7개의 숫자를 뽑습니다.
// 2. 이를 정렬한다.
// 3. 출력한다.

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

}

void Sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	
	}
	
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void Lotto(int arr[], int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 45 + 1;

		for (int j = 0; j < i; j++)
		{


			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}
}

int main()
{
	int arr[7] = {};
	int arrsize = (sizeof(arr) / sizeof(arr[0]));

	Lotto(arr, arrsize);

	Sort(arr, arrsize);

	PrintArr(arr, arrsize);

	return 0;
}