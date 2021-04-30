#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 100
#define INF 1000000000;

using namespace std;

int n = 6, result;

// �뷮, ����, �湮 ����
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> a[MAX];

void maxFlow(int st, int en) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(st);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				// �湮���� ���� ��� �߿��� �뷮�� ���� ���
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x; // ��θ� ����մϴ�.
					if (y == en) break; // �������� ������ �� ���
				}
			}
		}
		// ��� ��θ� �� ã�� �ڿ� Ż���մϴ�.
		if (d[en] == -1) break;
		int flow = INF;
		// �Ųٷ� �ּ� ���� Ž���մϴ�.
		for (int i = en; i != st; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// �ּ� ������ŭ �߰��մϴ�.
		for (int i = en; i != st; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;
	

	maxFlow(1, 6);
	cout << result;
}