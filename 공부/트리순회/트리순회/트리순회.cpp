/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.23
���� : Ʈ�� ��ȸ ����
Ǯ�� : Ʈ�� ��ȸ���� ũ�� 3������ �ִ�.
	   1) ���� ��ȸ
	   2) ���� ��ȸ
	   3) ���� ��ȸ

	   ���� ��ȸ
	   1. �ڱ� �ڽ��� ó���Ѵ�.
	   2. ���� �ڽ��� �湮�Ѵ�.
	   3. ������ �ڽ��� �湮�Ѵ�.

	   ���� ��ȸ
	   1. ���� �ڽ��� �湮�Ѵ�.
	   2. �ڱ� �ڽ��� ó���Ѵ�.
	   3. ������ �ڽ��� �湮�Ѵ�.

	   ���� ��ȸ
	   1. ���� �ڽ��� �湮�Ѵ�.
	   2. ������ �ڽ��� �湮�Ѵ�.
	   3. �ڱ� �ڽ��� �湮�Ѵ�.

	   ���� ��ȸ�� ���� ���α׷��� ���� �� ���� ���ȴ�
	   (����� ����ϴ� ������ ��ǻ�Ͱ� �����ϵ��� �� �� ���)
*/

#include<iostream>

using namespace std;

const int number = 15;

// �ϳ��� ��� ������ �����մϴ�.

/*
// C����� ���
// node��� ����ü�� treePointer��� �̸��� ������ �������� ����ϰڴ�.
typedef struct node *treePointer; 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;
*/

// C++�� ���
struct node {
	node* leftChild;
	node* rightChild;
	int data;
};

// C��� ����� ��� "node *ptr" -> "treePointer ptr" �� ����
// ���� ��ȸ�� �����մϴ�.
void preorder(node *ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ���� ��ȸ�� �����մϴ�.
void inorder(node *ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// ���� ��ȸ�� �����մϴ�.
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
	// ���ο� node ����
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