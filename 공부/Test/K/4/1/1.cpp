#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool chk(int num) {
	int cnt = 0;
	for (int i = 1; i <= num; i++)
		if (num % i == 0) cnt++;

	if (cnt % 2 == 0) return true;
	else return false;
}

int solution(int left, int right) {
	int answer = 0;

	for (int i = left; i <= right; i++) {
		if (chk(i)) answer += i;
		else answer -= i;
	}

	return answer;
}