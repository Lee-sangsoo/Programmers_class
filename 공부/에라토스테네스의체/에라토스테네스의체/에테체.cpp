/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.23
���� : �����佺�׳׽��� ü
Ǯ�� : ������ �Ҽ��� �Ǻ��ϴ� ���
*/
#include<iostream>

using namespace std;

const int number = 100000;
bool chk[100001];

void primeNumberSieve() {
	for (int i = 2; i <= number; i++) {
		if (chk[i]) continue;
		for (int j = i * 2; j <= number; j += i) {
			chk[j] = true;
		}
	}

	for (int i = 2; i <= number; i++) {
		if (!chk[i]) cout << i << ' ';
	}
}

int main() {
	primeNumberSieve();
}