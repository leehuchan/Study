#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>

#include "BST.h"
using namespace std;

// BST (BinarySearchTree)
// ���� : logN
// (key)Ž�� : logN
// ���� : logN
// 
// ����Ž��Ʈ��
// �ڰ����� ����Ž��Ʈ���� ����
// 1. �����Ʈ�� (map)
// 2. AVL Ʈ��

// �ڰ�����Ʈ��
// B-Ʈ�� (DB���� ���)

//           ����Ž��Ʈ��    vs     �ؽ����̺� (ǥ)
//            Node(key,data)       pair(key, data) 
//           key�� ����             �ؽ�(key...Algorithm) => Index
// Ž���ð�    logN                  1
// ���Խð�    logN                  1
// ����        logN                  1

// => ����Ž��Ʈ���� ���� ����
// 1. �����͸� ���� ����. (������ ����ȭ�� �Ǿ������� �ؽ����̺��� ���� ���� �� �ִ�.)
// 2. �ؽ��Լ��� ������ ������ ��� 'ü�̴�' �߻�

class Player
{
public:
	bool operator<(const Player& other) const
	{
		return hp < other.hp;
	}

	bool operator==(const Player& other) const
	{
		return hp == other.hp;
	}

	int hp;
	int atk;
};

int main()
{
	BinarySearchTree tree;
	tree.Insert(100);
	tree.Insert(50);
	tree.Insert(25);
	tree.Insert(75);
	tree.Insert(150);
	tree.Insert(110);
	tree.Insert(200);
	tree.Insert(99);

	tree.PrintTree(tree.root);

	map<string, int> m;

	// 1 (���������� 1�� ����� ���� ���)
	if (m.count("huchan") == 0)
		m["huchan"] = 1;
	// 2
	auto iter = m.insert(make_pair<string, int>("Huchan2", 2)); // map ������ �� ���� ���

	for (auto p : m)
	{
		cout << p.first << "... " << p.second << endl;
	}

	map<Player, int> pm;
	pm[{10, 5}] = 5;

	return 0;
}