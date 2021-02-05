/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.01
���� : �ܾ� ��ȯ
Ǯ�� : �̹� ������ ��Ʈ��ŷ�� �ſ� ������ Ǯ���̴�.
       �ٽ� �����غ��� dfs�� ��Ʈ��ŷ�� ���� ����ϴٰ� �� �� �ִ�.
	   �� �� ��� ��츦 ���̱��� Ž���ߴٰ� ó���ϴ°��̹Ƿ� �׷���.

	   Ǯ�̴� ������ ����
	   �켱 dfs�� ���� ���� �ܾ�� word �� �ܾ� ��
	   �� ���ڸ� �ٸ� ���� ã�� ���� �ܾ �ش� �ܾ�� �ٲ� ���� ����Ѵ�.

	   �׸��� �ѹ� ����� �ܾ �ٽ� ����ϸ� �ȵǹǷ� 
	   bool �迭�� ����Ͽ� �ش� �ܾ ��� ������ ǥ���Ѵ�.

	   �� ������ �ݺ��ϸ� target���� ��ȯ�� �����ϴٸ�
	   now�� target�� �������� �ñⰡ ���µ�, 
	   �� �� ��ȯ ������ ����� ������ �� �� �����Ƿ� 
	   ������ ������ �ʰ� ���� answer�� cnt�� ���Ͽ� ���� ���� �����Ѵ�.

	   �ѹ� ����� �ܾ �Ŀ��� ������� �ʾҴٰ� �ٽ� ��ǥ�� ���ִ� �͵� �� ���־�� �Ѵ�.
*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 51;
bool chk[51];

void dfs(string now, string target, vector<string> word, int cnt) {
	if (now == target) {
		answer = answer > cnt ? cnt : answer;
		return;
	}

	for (int i = 0; i < word.size(); i++) {
		if (chk[i]) continue;
		int diff = 0;
		for (int j = 0; j < word[i].length(); j++) {
			if (now[j] != word[i][j]) diff++;
			if (diff >= 2) break;
		}
		if (diff == 1) {
			chk[i] = true;
			dfs(word[i], target, word, cnt + 1);
			chk[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	dfs(begin, target, words, 0);
	if (answer == 51) return 0;
	return answer;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	//cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
}


/*
	�߰������� DFS�� ��Ʈ��ŷ�� �� ���̿� ���谡 �ִ�.
	��Ʈ��ŷ�� �ϴ� ���� �߿� 
	Ʈ���� ������ �κ��� DFS�� �����Ͽ� ��Ʈ��ŷ�� �Ϸ��Ű�� ���̾���.

	�򰥸��� ���� �� �ֽ�����.

			chk[i] = true;
			dfs(word[i], target, word, cnt + 1);
			chk[i] = false;
	�� �κ��� �߿�!
*/