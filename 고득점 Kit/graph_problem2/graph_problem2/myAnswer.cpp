/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.01
���� : �ܾ� ��ȯ
Ǯ�� : ���� Ǯ�̴� DFS�� BFS ���ٴ� ��Ʈ��ŷ�� �����ٰ� �� �� �ִ�.
       ��� ��츦 ���ƺ��� ���� �Ǵ°Ϳ��� �߰��� ���ֱ� ������
	   ó�� DFS/BFS ī�װ��� ������� �ؼ� �������θ� �����Ѱ� �����̿���.

	   ������ Ǯ�̴� �����ϴ�.
	   ��������� �Լ��� ���鼭 �ѹ��� + �ٸ� �ѹ��� - �� ���־
	   ��� ���ڸ� �� ���� �� ������ ����
	   target�� ������ ������ 1 �߰����ִ� ����� ����ߴ�.

	   �Ʒ��� �ִ� Ǯ�̴� ��Ʈ��ŷ�� �� �� ��Ʈ������ �ϴ� ����̴�.
	   �� ���ٰ� �� ���� �ְ� �ƴҼ��� �ִ�. (�˾ƴ� ����)
*/
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int target, int cnt, vector<int> n, int sum) {
	if (cnt == n.size()) {
		if (sum == target) answer++;
		return;
	}

	dfs(target, cnt + 1, n, sum + n[cnt]);
	dfs(target, cnt + 1, n, sum - n[cnt]);
}

int solution(vector<int> numbers, int target) {
	dfs(target, 0, numbers, 0);
	return answer;
}

int main() {
	cout << solution({ 1,1,1,1,1 }, 3);
}


/*
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int size = 1 << numbers.size();

	for(int i = 1 ; i < size ; i++){  // (00001 ~ 11111)
		int temp = 0;
		for(int j = 0 ; j < numbers.size() ; j++)
		{
			if(i &(1 << j)){ // �ٽ� �κ�
				temp -= numbers[j]; // (numbers[0] ~ numbers[4])
			}
			else temp += numbers[j];
		}
		if(temp == target) answer++;
	}
	return answer;
}
*/