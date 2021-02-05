/*
작성자 : 이상수
일시 : 2021.02.05
제목 : 삼각 달팽이
풀이 : 예전에 프로그래머스 대회에서 풀었던 문제인데 문제로 나와 있어서 다시 풀어보았다.

	   비교적 간단하다.
	   배열을 비스듬하게 두고 생각하지 않고
	   계단 모양으로 두고 생각하면 간단하게 구현이 가능하다.
	   배열의 요소를 arr[x][y]라고 할 때,
	   1. x++
	   2. y++
	   3. x-- y--
	   를 해주면 된다.

	   다만, 마지막 반복에 x와 y값이 추가되어 나오거나 감소되어 나오기 때문에
	   계산하여 이를 추가 감소 해주어야 한다.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> tmp;

	for (int i = 1; i <= n; i++) {
		vector<int> zero;
		for (int j = 0; j < i; j++) {
			zero.push_back(0);
		}
		tmp.push_back(zero);
	}

	int x = 0, y = 0;
	int cnt = 1;
	while (1) {
		if (n < 1) break;
		for (int i = 0; i < n; i++) {
			tmp[x][y] = cnt;
			cnt++;
			x++;
		}
		n--;
		if (n < 1) break;
		x--;
		y++;

		for (int i = 0; i < n; i++) {
			tmp[x][y] = cnt;
			cnt++;
			y++;
		}
		n--;
		if (n < 1) break;
		y -= 2;
		x--;

		for (int i = 0; i < n; i++) {
			tmp[x][y] = cnt;
			cnt++;
			x--; y--;
		}
		n--;
		if (n < 1) break;
		y++;
		x += 2;
	}

	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp[i].size(); j++)
			answer.push_back(tmp[i][j]);
	}

	return answer;
}

int main() {
	vector<int> sol = solution(5);
	for (auto i : sol)
		cout << i << ' ';
}