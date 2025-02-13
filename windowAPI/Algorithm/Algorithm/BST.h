#pragma once

#include <iostream>

using namespace std;

struct Node
{
	Node() {}
	Node(int key) { this->key = key; }

	int data = 0;
	int key = -1;

	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	void Insert(int key);
	void PrintTree(Node* node);

	Node* Search(Node* node, int key); // key���� ������ ��� ��ȯ
	Node* Min(Node* node); // node���� �����ϴ� Ʈ������ ���� ���� ���� ������ ��� ��ȯ
	Node* Max(Node* node); // node���� �����ϴ� Ʈ������ ���� ū ���� ������ ��� ��ȯ

	Node* Previous(Node* node); // �Ű����� node���� �� ĭ �� ���� ��
	Node* Next(Node* node); // �Ű����� node���� �� ĭ �� ū ��

	void Replace(Node* node1, Node* node2);;
	void Delete(Node* node);

	Node* root = nullptr;
};