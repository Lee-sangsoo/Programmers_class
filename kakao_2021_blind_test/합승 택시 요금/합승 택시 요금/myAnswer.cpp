/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.09
���� : �ս� �ý� ���
Ǯ�� : �÷��̵� �˰����� ����ϸ� �Ǵ� ����
       �󶳰ῡ īī�� ��ũ���� ���� Ǯ�̸� �����ȴ�.
	   ó�� ������ ������ ��������� ������, Ǯ�̸� �� �������� ���� �����ߴ�.

	   �÷��̵� �˰����� ���� �� ���������� �ּ� �Ÿ��� ���� ����
	   1. ���� ����(S)���� �ս��� ��ĥ ����(i)������ ���
	   2. �ս��� ���� ����(i)���� A�� ���� �ִ� ����(a) ������ ���
	   3. �ս��� ���� �������� B�� ���� �ִ� ����(b) ������ ���
	   ��� ������ ��ȸ�ϸ� 1, 2, 3�� ���� �� �� ���� ���� ���� �����ϵ��� �Ѵ�.

	   �̰� �����̴�.

	   �ٸ�, �÷��̵� �˰����� ���� ó���� 987654321�� ��� 
	   �ս��� ��ģ ������ �ڽ��� ���� ��쵵 �ֱ� ������ 
	   �÷��̵� �˰����� ��ģ ������ [i][i] = �ڱ� �ڽ������� ����� 0���� ó�����־�� �Ѵ�.
	   (�Ʒ��� �ִ� �ڵ�� 0������ ó���� ���� �ʾƼ� ���ǹ��� ���� �������̴�)

	   �׸��� ���ʰ��� �ʹ� ũ�� ��Ƽ� continue���� ������� ������ �����÷ο찡 �����.
	   answer�� long long���� �ְų� continue�� �ָ� �ذ�Ǿ���
	   (���� ���ٴ� ���̹Ƿ� continue�� ó���ϴ°� ������ ����)
*/
#include <iostream>
#include <vector>

using namespace std;

int dist[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}

	for (int i = 0; i < fares.size(); i++) {
		for (int j = 0; j < fares[i].size(); j++) {
			dist[fares[i][0]][fares[i][1]] = fares[i][2];
			dist[fares[i][1]][fares[i][0]] = fares[i][2];
		}
	}

	for (int n1 = 1; n1 <= n; n1++) { // ���İ��� ����
		for (int n2 = 1; n2 <= n; n2++) { // ���� ����
			for (int n3 = 1; n3 <= n; n3++) { // ���� ����
				if (dist[n2][n3] > dist[n2][n1] + dist[n1][n3])
					dist[n2][n3] = dist[n2][n1] + dist[n1][n3];
			}
		}
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0; // ��� �ڱ� �ڽ������� ��� 0

	answer = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++) {
		// continue �κ��� ó���ϱ� �ȴٸ� ���� �ʹ� Ŀ���� ������ long long���� �ٲ��ָ� �ȴ�.
		if (dist[s][i] == 987654321 || dist[i][a] == 987654321 || dist[i][b] == 987654321) continue;
		if (answer > dist[s][i] + dist[i][a] + dist[i][b])
			answer = dist[s][i] + dist[i][a] + dist[i][b];
		
	}

	return answer;
}

int main() {
	
}

/*
	// ó�� ������ ��� i -> i�� ���� �κ��� 0���� ó������ �ʾƼ� ��� ������ Ȯ���ߴ�.
	// �� Ǯ�̿��� �׳� dist[i][i]�� 0���� �ʱ�ȭ �ϸ� �Ǵ� ��������.
	answer = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++) {
		if (dist[s][i] == 987654321 || dist[i][a] == 987654321 || dist[i][b] == 987654321) continue;

		if (i == a || i == b) {
			if (i == a && i == b) {
				if (answer > dist[s][i])
					answer = dist[s][i];
			}
			else if (i == a) {
				if (answer > dist[s][i] + dist[i][b])
					answer = dist[s][i] + dist[i][b];
			}
			else if (i == b) {
				if (answer > dist[s][i] + dist[i][a])
					answer = dist[s][i] + dist[i][a];
			}
		}
		else {
			if (answer > dist[s][i] + dist[i][a] + dist[i][b])
				answer = dist[s][i] + dist[i][a] + dist[i][b];
		}

	}
*/