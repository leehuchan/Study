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

	// 1. v에서 23이 있는 원소의 자리(iter)를 찾아주세요.
	cout << "1. v에서 23이 있는 원소의 자리(iter)를 찾아주세요." << endl;
	
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


	//if (iter != v.end()) // 찾음
	//{
	//	cout << *iter << endl;
	//}
	//cout << "--------------------------------------" << endl;


	// 2. v에서 25보다 큰 수가 있다면 그 자리를 찾아주세요.
	cout << "2. v에서 25보다 큰 수가 있다면 그 자리를 찾아주세요." << endl;
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

	cout << "25보다 큰 수는 ";
	cout << *it << "입니다." << endl;

	cout << "--------------------------------------" << endl;

	// 3. v에서 3의 개수가 몇개인지
	int mycount = 0;

	mycount = count(v.begin(), v.end(), 3);
	cout << "3. v에서 3의 개수는 몇개?" << endl;
	cout << mycount << endl;
	cout << "--------------------------------------" << endl;

	// 4. v에서 10보다 큰 수는 몇개인지
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

	cout << "4. v에서 10보다 큰 수는 몇개?" << endl;
	cout << mycount << endl;
	cout << "--------------------------------------" << endl;


	// 5. v에서 모든 수가 50보다 작은지
	Find_If_Functor1 functor2;

	functor2.compareNum = 50;

	cout << "5. v에서 모든 수가 50보다 작은가?" << endl;

	//mycount = count_if(v.begin(), v.end(), functor2);
	//if (mycount == v.size())
	//{
	//	cout << "모든 수가 " << functor2.compareNum << "보다 작습니다.";
	//}
	//else
	//{
	//	cout << "모든 수가 " << functor2.compareNum << "보다 작지 않습니다.";
	//}

	if (all_of(v.begin(), v.end(), functor2))
	{
		cout << "모든 수가 " << functor2.compareNum << "보다 작습니다." << endl;
	}
	else
	{
		cout << "모든 수가 " << functor2.compareNum << "보다 작지 않습니다." << endl;
	}

	cout << "--------------------------------------" << endl;

	// 6. v에서 하나라도 20보다 크고 30보다 작은 수가 있는지
	cout << "6. v에서 하나라도 20보다 크고 30보다 작은 수가 있는가?" << endl;

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
		cout << "v에서 하나라도 " << functor3.compareNum1 << "보다 크고 " << functor3.compareNum2 << "보다 작은 수가 있습니다." << endl;
	}
	else
	{
		cout << "v에서 하나라도 " << functor3.compareNum1 << "보다 크고 " << functor3.compareNum2 << "보다 작은 수가 없습니다." << endl;
	}

	cout << "--------------------------------------" << endl;


	// 7. v의 배열을 거꾸로 만들어주세요.
	cout << "7. v의 배열을 거꾸로 만들어주세요. " << endl;

	reverse(v.begin(), v.end());

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;

	// 8. 각 v의 원소에 3을 곱해주세요.
	cout << "8. 각 v의 원소에 3을 곱해주세요. " << endl;
	
	for_each(v.begin(), v.end(), Multiple);

	// FN은 각 원소가 매개변수로 들어가는 함수 시그니처를 가져야한다.

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;

	// 9. v를 정렬해주세요.
	cout << "9. v를 정렬해주세요. " << endl;

	sort(v.begin(), v.end(), myfunctionSort);

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "--------------------------------------" << endl;

	
	// 10. v에서 중복된 원소가 있다면 삭제해주세요.
	cout << "10. v에서 중복된 원소가 있다면 삭제해주세요. " << endl;

	v.erase(unique(v.begin(), v.end()));

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;

	
	// 11. v에서 45인 원소가 있다면 삭제해주세요.
	cout << "11. v에서 45인 원소가 있다면 삭제해주세요. " << endl;

	int removeNum = 45;
	v.erase(remove(v.begin(), v.end(), removeNum));

	iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "--------------------------------------" << endl;
	
	// 12. v에서 20보다 작은 원소를 삭제해주세요.
	cout << "12. v에서 20보다 작은 원소를 삭제해주세요. " << endl;

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