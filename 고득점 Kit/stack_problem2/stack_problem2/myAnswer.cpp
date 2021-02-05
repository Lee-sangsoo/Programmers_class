/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.22
���� : �ٸ��� ������ Ʈ��
Ǯ�� : queue�� ����ϴ� �����̴�.
       ������ �����ϴµ� ���� �ð��� �ɷȴ�.
	   �� ���� ������ ���� ���� ���� ���� �򰥷ȴµ�
	   �̴� ť���� pop�� �� ������ �ð��� ������Ű�� ������ �ذ�Ǿ���.

	   ���� Ǯ�̴� ������ ����
	   �켱 Ʈ���� ���԰� 1���� �����̱� ������ 
	   ���� ���� ť�� 0���� �ٸ��� ���� - 1 ��ŭ ä���ش�.

	   �׸��� ���� �ݺ����� ���� �� Ʈ������
	   �ٸ��� �ö� �� �ִٸ� �ش� ���Ը� push �ϰ�
	   �ٸ��� �ö� �� ���ٸ� 0�� push �Ͽ���.

	   �ݺ����� ���鼭 �ٸ��� Ʈ���� �ø��ų� ���ø� ���� �ð��� �����ϰ�
	   Ʈ������ ������ �ð��� ������Ű�� �ʾҴ�.

	   ��� Ʈ���� �ٸ���(ť��) �ö󰬴ٸ�
	   �ݺ����� �������� ��� Ʈ���� �ٸ����� ����������
	   pop�� �����ϸ� �ð��� 1�ʾ� ���������ش�.
���ѻ��� : bridge_length�� 1 �̻� 10,000 �����Դϴ�.
		   weight�� 1 �̻� 10,000 �����Դϴ�.
		   truck_weights�� ���̴� 1 �̻� 10,000 �����Դϴ�.
		   ��� Ʈ���� ���Դ� 1 �̻� weight �����Դϴ�.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	queue<int> q;

	for (int i = 0; i < bridge_length-1; i++)
		q.push(0);

	int cnt = 0;
	while (cnt < truck_weights.size()) {
		if (q.size() == bridge_length) { // �ٸ��� ���� �� �ִٸ�
			weight += q.front();
			q.pop();
		}

		if (weight >= truck_weights[cnt]) { // Ʈ���� �ø� �� �ִٸ� �ش� ����
			weight -= truck_weights[cnt];
			q.push(truck_weights[cnt]);
			answer++;
			cnt++;
		}
		else { // ���ٸ� 0
			q.push(0);
			answer++;
		}
	}

	while (!q.empty()) { // �� �� ���� �ݺ�
		answer++;
		q.pop();
	}

	return answer;
}

int main() {
	cout << solution(2, 10, { 7,4,5,6 });
}