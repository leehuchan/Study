#include <iostream>
#include <string>

using namespace std;

// ���ڿ� Ư¡
// �� �� ��Ʈ�� 0���� ������ ���ڿ��� �����ٰ� �Ǵ��Ѵ�.
// Escape Sequence
// /0 : 0
// \t : tap
// \' : '
// \n : ���� ��

// ���ڿ��� ����
unsigned __int64 Length(const char* str)
{
	unsigned __int64 count = 0;

	for (int i = 0; true; i++)
	{

		if(str[i] == '0')
			break;
		count++;
	}
	return count;
}

// ���ڿ� ��
bool Compare(const char* str1, const char* str2)
{


	return true;
}



int main()
{
	const char* str1 = "Hello";
	char str2[7] = { 'H','e','l','l','o','/0', 0};

	cout << str1 << endl;
	cout << str2 << endl;

	if (Compare(str1, str2) == true)
	{
		cout << "���ڿ��� �����ϴ�." << endl;
	}
	else
	{
		cout << "���ڿ��� �ٸ��ϴ�." << endl;
	}

	return 0;
}