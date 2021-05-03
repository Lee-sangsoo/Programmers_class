/*
작성자 : 이상수
일시 : 2021.04.23
제목 : 에라토스테네스의 체
풀이 : 빠르게 소수를 판별하는 방식
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