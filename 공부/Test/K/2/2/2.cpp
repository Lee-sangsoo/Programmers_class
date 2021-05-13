#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
char arr[5][5][5];

bool chk(int c, int n, int m, int a, int b) {
	// (n, m) - (a, b)
	//cout << "(" << n << "," << m << "), (" << a << "," << b << ")" << '\n';
	int d1 = n > a ? n - a : a - n;
	int d2 = m > b ? m - b : b - m;

	int dist = d1 + d2;

	if (dist < 2) return false;
	if (dist > 2) return true;

	// (n, m)이 (a, b)과 같은 행에 있을 때
	if (n == a) {
		if (m > b) {
			if (arr[c][a][b + 1] == 'X') return true;
			else if (arr[c][a][b + 1] == 'O') return false;
		}
		else {
			if (arr[c][n][m + 1] == 'X') return true;
			else if (arr[c][n][m + 1] == 'O') return false;
		}
	}
	// (n, m)이 (a, b)과 같은 열에 있을 때
	else if (m == b) {
		if (n > a) {
			if (arr[c][a + 1][b] == 'X') return true;
			else if (arr[c][a + 1][b] == 'O') return false;

		}
		else {
			if (arr[c][n + 1][m] == 'X') return true;
			else if (arr[c][n + 1][m] == 'O') return false;
			
		}
	}
	// (n, m)과 (a, b)가 서로 다른 행과 열에 있을 때
	else {
		if (n - 1 == a && m - 1 == b) {
			if (arr[c][a][b + 1] == 'X' && arr[c][a + 1][b] == 'X') return true;
			else return false;
		}
		else if (n - 1 == a && m + 1 == b) {
			if (arr[c][a][b - 1] == 'X' && arr[c][a + 1][b] == 'X') return true;
			else return false;
		}
		else if (n + 1 == a && m - 1 == b) {
			if (arr[c][a - 1][b] == 'X' && arr[c][a][b + 1] == 'X') return true;
			else return false;
		}
		else if (n + 1 == a && m + 1 == b) {
			if (arr[c][a - 1][b] == 'X' && arr[c][a][b - 1] == 'X') return true;
			else return false;
		}
	}

	return false;
}

bool dfs(int c, int n, int m) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == n && j == m) continue;
			if (arr[c][i][j] == 'P') {
				if (!chk(c, n, m, i, j)) return false;
			}
		}
	}
	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	
	for (int i = 0; i < places.size(); i++) {
		for (int j = 0; j < places[i].size(); j++) {
			string cur = places[i][j];
			for (int k = 0; k < cur.length(); k++) {
				arr[i][j][k] = cur[k];
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		bool can = true;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (arr[i][j][k] == 'P') {
					if (!dfs(i, j, k)) {
						can = false;
						break;
					}
				}
			}
			if (!can) break;
		}

		if (can) answer.push_back(1);
		else answer.push_back(0);
	}

	return answer;
}

int main() {
	vector<int> tmp = solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
	for (int i : tmp)
		cout << i << ' ';

}