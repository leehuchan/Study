#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// 트리
// 1. 계층적 구조를 나타내는 자료구조(부모와 자식관계) - 높이, 깊이
// 2. 트리는 잘라도 트리이다. (서브트리의 존재) - 트리는 재귀적 속성을 가지고 있음

// 트리의 종류
// 1. 이진 트리
// 2. 포화이진트리
// 3. 완전이진트리 - 추가 될 때는 왼쪽 아래부터 삭제는 오른쪽 아래부터
// 4. 힙트리
// 5. (자가균형)이진탐색트리

struct Node
{
	string data;

	vector<Node*> children;

};

Node* CreateTree()
{
	// c 스타일
	Node* root = new Node();
	root->data = "개발팀";

	// 프로그래밍 팀
	Node* programing = new Node();
	programing->data = "프로그래밍팀";
	root->children.push_back(programing);
	{
		Node* node1 = new Node();
		node1->data = "클라이언트";
		programing->children.push_back(node1);

		Node* node2 = new Node();
		node2->data = "서버";
		programing->children.push_back(node2);

		Node* node3 = new Node();
		node3->data = "엔진";
		programing->children.push_back(node3);
	}

	// 기획 팀
	Node* planing = new Node();
	planing->data = "기획팀";
	root->children.push_back(planing);
	{
		Node* node1 = new Node();
		node1->data = "스토리";
		planing->children.push_back(node1);

		Node* node2 = new Node();
		node2->data = "레벨 디자인";
		planing->children.push_back(node2);

		Node* node3 = new Node();
		node3->data = "컨텐츠";
		planing->children.push_back(node3);
	}

	// 아트 팀
	Node* art = new Node();
	art->data = "아트팀";
	root->children.push_back(art);
	{
		Node* node1 = new Node();
		node1->data = "원화";
		art->children.push_back(node1);

		Node* node2 = new Node();
		node2->data = "배경";
		art->children.push_back(node2);

		Node* node3 = new Node();
		node3->data = "모델";
		art->children.push_back(node3);
	}

	return root;
}

void PrintTree(Node* node, int depth = 0)
{
	// Tree의 전위 순회 : 부모 - 왼쪽 자식 - 오른쪽 자식
	// Tree의 중위 순회 : 왼쪽 자식 - 부모 - 오른쪽 자식
	// Tree의 후위 순회 : 왼쪽 자식 - 오른쪽 자식 - 부모

	for (int i = 0; i < depth; i++)
	{
		cout << "-";
	}

	// 트리의 전위 순회
	cout << node->data << endl;

	for (auto child : node->children)
	{
		PrintTree(child, depth + 1);
	}
	// 트리의 휘위 순회
	// cout << node->data << endl;
}

int main()
{
	Node* root = CreateTree();

	PrintTree(root);

	return 0;
}