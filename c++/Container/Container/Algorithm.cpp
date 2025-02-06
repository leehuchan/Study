#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool Find_if(int element)
{
	if (element > 25)
		return true;
	return false;
}

bool myfunctionSort(int i, int j) { return (i < j); }

void Multiple(int& value)
{
	value *= 3;
}

bool myfunctionUnique(int i, int j)
{
	return (i == j);
}

bool myfunctionRemoveIf(int i, int compare) { return ((i < compare)); }
	
int main()
{
	vector<int> v = { 31, 23, 3, 2, 1, 3, 12, 15, 19 };

	// 1. v���� 23�� �ִ� ������ �ڸ�(iter)�� ã���ּ���.
	cout << "1. v���� 23�� �ִ� ������ �ڸ�(iter)�� ã���ּ���." << endl;
	
	//int targetIndex = 0;
	//for (int i = 0; v.size(); i++)
	//{
	//	if (v[i] == 23)
	//	{
	//		targetIndex = i;
	//		break;
	//	}
	//}

	//cout << targetIndex << endl;

	// cout << "--------------------------------------" << endl;
	// iterator
	vector<int>::iterator iter;
	iter = v.begin();

	int i = 0;

	for (iter; iter != v.end(); iter++)
	{
		if (*iter == 23)
		{
			break;
		}

		i++;

	}

	cout << i << endl;

	iter = find(v.begin(), v.end(), 23);
	cout << "--------------------------------------" << endl;


	//if (iter != v.end()) // ã��
	//{
	//	cout << *iter << endl;
	//}
	//cout << "--------------------------------------" << endl;


	// 2. v���� 25���� ū ���� �ִٸ� �� �ڸ��� ã���ּ���.
	cout << "2. v���� 25���� ū ���� �ִٸ� �� �ڸ��� ã���ּ���." << endl;
	iter = v.begin();
	int j = 0;

	for (iter; iter != v.end(); iter++)
	{
		if (*iter > 25)
			break;
		j++;
	}

	cout << j << endl;

	// cout << *iter << endl;

	// cout << "--------------------------------------" << endl;

	// find_if(v.begin(), v.end(), &Find_if);

	// cout << *iter << endl;

	struct Find_If_Functor
	{
		bool operator()(int element)
		{
			if (element > compareNum)
				return true;
			return false;
		}

		int compareNum;

	};

	Find_If_Functor functor1;

	functor1.compareNum = 25;

	vector<int>::iterator it = find_if(v.begin(), v.end(), functor1);

	cout << "25���� ū ���� ";
	cout << *it << "�Դϴ�." << endl;

	cout << "--------------------------------------" << endl;

	// 3. v���� 3�� ������ �����
	int mycount = 0;

	mycount = count(v.begin(), v.end(), 3);
	cout << "3. v���� 3�� ������ �?" << endl;
	cout << mycount << endl;
	cout << "--------------------------------------" << endl;

	// 4. v���� 10���� ū ���� �����
	int mycount1 = 0;

	struct Find_If_Functor1
	{
		bool operator()(int element)
		{
			if (element < compareNum)
				return true;
			return false;
		}

		int compareNum;

	};

	functor1.compareNum = 10;

	mycount = count_if(v.begin(), v.end(), functor1);

	cout << "4. v���� 10���� ū ���� �?" << endl;
	cout << mycount << endl;
	cout << "--------------------------------------" << endl;


	// 5. v���� ��� ���� 50���� ������
	Find_If_Functor1 functor2;

	functor2.compareNum = 50;

	cout << "5. v���� ��� ���� 50���� ������?" << endl;

	//mycount = count_if(v.begin(), v.end(), functor2);
	//if (mycount == v.size())
	//{
	//	cout << "��� ���� " << functor2.compareNum << "���� �۽��ϴ�.";
	//}
	//else
	//{
	//	cout << "��� ���� " << functor2.compareNum << "���� ���� �ʽ��ϴ�.";
	//}

	if (all_of(v.begin(), v.end(), functor2))
	{
		cout << "��� ���� " << functor2.compareNum << "���� �۽��ϴ�." << endl;
	}
	else
	{
		cout << "��� ���� " << functor2.compareNum << "���� ���� �ʽ��ϴ�." << endl;
	}

	cout << "--------------------------------------" << endl;

	// 6. v���� �ϳ��� 20���� ũ�� 30���� ���� ���� �ִ���
	cout << "6. v���� �ϳ��� 20���� ũ�� 30���� ���� ���� �ִ°�?" << endl;

	struct Find_If_Functor3
	{
		bool operator()(int element)
		{
			if (element > compareNum1 && element < compareNum2)
				return true;
			return false;
		}

		int compareNum1;
		int compareNum2;

	};

	Find_If_Functor3 functor3;

	functor3.compareNum1 = 20;
	functor3.compareNum2 = 30;


	if (any_of(v.begin(), v.end(), functor3))
	{
		cout << "v���� �ϳ��� " << functor3.compareNum1 << "���� ũ�� " << functor3.compareNum2 << "���� ���� ���� �ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "v���� �ϳ��� " << functor3.compareNum1 << "���� ũ�� " << functor3.compareNum2 << "���� ���� ���� �����ϴ�." << endl;
	}

	cout << "--------------------------------------" << endl;


	// 7. v�� �迭�� �Ųٷ� ������ּ���.
	cout << "7. v�� �迭�� �Ųٷ� ������ּ���. " << endl;

	reverse(v.begin(), v.end());

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;

	// 8. �� v�� ���ҿ� 3�� �����ּ���.
	cout << "8. �� v�� ���ҿ� 3�� �����ּ���. " << endl;
	
	for_each(v.begin(), v.end(), Multiple);

	// FN�� �� ���Ұ� �Ű������� ���� �Լ� �ñ״�ó�� �������Ѵ�.

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;

	// 9. v�� �������ּ���.
	cout << "9. v�� �������ּ���. " << endl;

	sort(v.begin(), v.end(), myfunctionSort);

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;

	
	// 10. v���� �ߺ��� ���Ұ� �ִٸ� �������ּ���.
	cout << "10. v���� �ߺ��� ���Ұ� �ִٸ� �������ּ���. " << endl;

	v.erase(unique(v.begin(), v.end()));

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;

	
	// 11. v���� 45�� ���Ұ� �ִٸ� �������ּ���.
	cout << "11. v���� 45�� ���Ұ� �ִٸ� �������ּ���. " << endl;

	int removeNum = 45;
	v.erase(remove(v.begin(), v.end(), removeNum));

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;
	
	// 12. v���� 20���� ���� ���Ҹ� �������ּ���.
	cout << "12. v���� 20���� ���� ���Ҹ� �������ּ���. " << endl;

	int compareNum = 20;

	struct Remove_IF
	{
		bool operator()(const int& element)
		{
			return element < removeCompare;
		}
		int removeCompare;
	};
	Remove_IF fn;

	fn.removeCompare = 20;
	v.erase(remove_if(v.begin(), v.end(), fn), v.end());

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}