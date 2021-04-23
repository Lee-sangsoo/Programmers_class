/*
작성자 : 이상수
일시 : 2021.04.23
제목 : 트리 순회 공부
풀이 : 트리 순회에는 크게 3가지가 있다.
	   1) 전위 순회
	   2) 중위 순회
	   3) 후위 순회

	   전위 순회
	   1. 자기 자신을 처리한다.
	   2. 왼쪽 자식을 방문한다.
	   3. 오른쪽 자식을 방문한다.

	   중위 순회
	   1. 왼쪽 자식을 방문한다.
	   2. 자기 자신을 처리한다.
	   3. 오른쪽 자식을 방문한다.

	   후위 순회
	   1. 왼쪽 자식을 방문한다.
	   2. 오른쪽 자식을 방문한다.
	   3. 자기 자신을 방문한다.

	   후위 순회는 계산기 프로그램을 만들 때 많이 사용된다
	   (사람이 사용하는 수식을 컴퓨터가 이해하도록 할 때 사용)
*/

#include<iostream>

using namespace std;

const int number = 15;

// 하나의 노드 정보를 선언합니다.

/*
// C언어의 방식
// node라는 구조체를 treePointer라는 이름의 포인터 형식으로 사용하겠다.
typedef struct node *treePointer; 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;
*/

// C++의 방식
struct node {
	node* leftChild;
	node* rightChild;
	int data;
};

// C언어 방식의 경우 "node *ptr" -> "treePointer ptr" 로 변경
// 전위 순회를 구현합니다.
void preorder(node *ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회를 구현합니다.
void inorder(node *ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회를 구현합니다.
void postorder(node *ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[number + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) nodes[i / 2].leftChild = &nodes[i];
		else nodes[i / 2].rightChild = &nodes[i];
	}

	/*
	// 새로운 node 생성
	node *tree;
	tree = (node*)malloc(sizeof(node));
	tree->data = 1;
	tree->leftChild = NULL;
	tree->rightChild = NULL;
	*/

	preorder(&nodes[1]);
	cout << '\n';

	inorder(&nodes[1]);
	cout << '\n';

	postorder(&nodes[1]);
	cout << '\n';
}