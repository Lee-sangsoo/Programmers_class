/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.05
���� : �ﰢ ������
Ǯ�� : ������ ���α׷��ӽ� ��ȸ���� Ǯ���� �����ε� ������ ���� �־ �ٽ� Ǯ��Ҵ�.

	   ���� �����ϴ�.
	   �迭�� �񽺵��ϰ� �ΰ� �������� �ʰ�
	   ��� ������� �ΰ� �����ϸ� �����ϰ� ������ �����ϴ�.
	   �迭�� ��Ҹ� arr[x][y]��� �� ��,
	   1. x++
	   2. y++
	   3. x-- y--
	   �� ���ָ� �ȴ�.

	   �ٸ�, ������ �ݺ��� x�� y���� �߰��Ǿ� �����ų� ���ҵǾ� ������ ������
	   ����Ͽ� �̸� �߰� ���� ���־�� �Ѵ�.
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