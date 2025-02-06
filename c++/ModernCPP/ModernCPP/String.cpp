#include <iostream>
#include <string>

using namespace std;

// 문자열 특징
// 맨 뒷 비트가 0으로 끝나야 문자열이 끝났다고 판단한다.
// Escape Sequence
// /0 : 0
// \t : tap
// \' : '
// \n : 다음 줄

// 문자열의 길이
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

// 문자열 비교
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
		cout << "문자열이 같습니다." << endl;
	}
	else
	{
		cout << "문자열이 다릅니다." << endl;
	}

	return 0;
}