/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.04
���� : īī�������� �÷�����
Ǯ�� : BFS�� DFS�� ���� 2���� �迭�� ��ȸ�ϸ� ����� ���� �ִ��� Ȯ���ϸ� �ִ밪�� ���ϸ� �ȴ�.

	   �����ؾ� �ϴ� �����δ�
	   1. ���� ������ ���� �ϱ� ������ 0�� �ƴѰ��� ���°� �ƴ�
	   ���ο� ���� ���� ���ÿ� �ִ� ���� ���� ���� ���� ���� �߰��Ѵ�.

	   2. 0�� �ƴ� ���� ��ȸ�ϰ��� �� �� ���ο� ���� ���ÿ� ���ٴ� ����
	   ���ٿ����� ���°��� ���ٴ� ���̱� ������ ���ο� �����̴�.

	   �̸� �����ϸ� DFS�� BFS�� �̿��ϸ� �����ϰ� Ǯ�� �����ϴ�

	   �ٵ� ���� �׽�Ʈ ���̽��� �ϳ���.... ����....
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	int paper[101][101] = { 0, };
	bool chk[101][101] = { 0, };
	int dist_x[4] = { 0,1,0,-1 };
	int dist_y[4] = { 1,0,-1,0 };

	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			paper[i][j] = picture[i][j];
		}
	}

	stack<pair<int, int>> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] != 0 && !chk[i][j]) {
				number_of_area++;
				s.push(make_pair(i, j));
				chk[i][j] = true;
				int cnt = 1;
				while (!s.empty()) {
					int x = s.top().first;
					int y = s.top().second;
					s.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dist_x[k];
						int ny = y + dist_y[k];
						if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
							if (!chk[nx][ny] && paper[x][y] == paper[nx][ny]) {
								s.push(make_pair(nx, ny));
								chk[nx][ny] = true;
								cnt++;
							}
						}
					}

				}
				max_size_of_one_area = max_size_of_one_area < cnt ? cnt : max_size_of_one_area;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	//vector<int> tmp = solution(6, 4, { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} });
	vector<int> tmp = solution(1, 1, { {1} });
	cout << tmp[0] << ' ' << tmp[1];
}