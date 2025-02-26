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

	Node* Search(Node* node, int key); // key값을 가지는 노드 반환
	Node* Min(Node* node); // node부터 시작하는 트리에서 가장 작은 값을 가지는 노드 반환
	Node* Max(Node* node); // node부터 시작하는 트리에서 가장 큰 값을 가지는 노드 반환

	Node* Previous(Node* node); // 매개변수 node보다 한 칸 더 작은 것
	Node* Next(Node* node); // 매개변수 node보다 한 칸 더 큰 것

	void Replace(Node* node1, Node* node2);;
	void Delete(Node* node);

	Node* root = nullptr;
};