/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.21
���� : ���߿켱����ť
Ǯ�� : �������� Ǯ�̴� multiset�� ����ϴ� ����ε�, ó���� �� ¥�� �س����
       multiset�� ��ȸ�ϴ� ��İ� ��ȸ�ϸ� ���� �������� ����� ������.
	   �ٸ� ����� Ǯ�̸� ���� �ش� ����� �˾Ҵ�.

	   ���� Ǭ ����� �� �����ϱ⵵ �ϰ� �����.
	   
	   �켱 �켱���� ť�� 2�� ����
	   �ϳ��� �ִ밪 ��
	   �ٸ� �ϳ��� �ּҰ� �� ���� �����.

	   �׸��� ���� �� ��ɾ �°� �ְ�
	   ������ ��� 1�̸� �ִ밪 ���� pop
	              -1�̸� �ּҰ� ���� pop
	   �Ͽ� ���� ����� ��������

	   �� ������ vector�� �� �־��ش�.
	   �׸��� ������ �����Ͽ� 
	   vector�� ��ȸ�ϸ� ���� ��ġ�ϸ� �������� break �ϴ� ����� ����ߴ�.

	   2���� �켱���� ť�� ����ϴ� ����, ���� �ִ��� ������ �ľ��ϴ°�
	   ���� �����.
	   �׷��� �� �ڷᱸ�� �� �ϳ��� ����ų� 
	   ��ɾ� I�� Ƚ���� D�� Ƚ���� ���ų� D�� ū ���� {0, 0}�� ��ȯ�ߴ�.
���ѻ��� : number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ ���� (string)
		   k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ���
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int, vector<int>, less<int>> gp;
	priority_queue<int, vector<int>, greater<int>> lp;

	int dc = 0;
	int ic = 0;

	for (int i = 0; i < operations.size(); i++) {
		char inst = operations[i][0];
		int num = stoi(operations[i].substr(2));

		if (inst == 'I') {
			ic++;
			gp.push(num);
			lp.push(num);
		}
		else {
			dc++;
			if (num == 1) {
				if (gp.empty()) continue;
				gp.pop();
			}
			else {
				if (lp.empty()) continue;
				lp.pop();
			}
		}
	}

	vector<int> gv;
	vector<int> lv;
	while (!gp.empty()) {
		gv.push_back(gp.top());
		gp.pop();
	}

	while (!lp.empty()) {
		lv.push_back(lp.top());
		lp.pop();
	}

	if (gv.empty() || lv.empty() || ic <= dc) return { 0,0 };

	sort(gv.begin(), gv.end());

	bool chk = false;
	for (int i = gv.size() - 1; i >= 0; i--) {
		for (int j = lv.size() - 1; j >= 0; j--) {
			if (gv[i] == lv[j]) {
				chk = true;
				answer.push_back(gv[i]);
				break;
			}
		}
		if (chk) break;
	}

	chk = false;
	for (int i = 0; i < gv.size(); i++) {
		for (int j = 0; j < lv.size(); j++) {
			if (gv[i] == lv[j]) {
				chk = true;
				answer.push_back(gv[i]);
				break;
			}
		}
		if (chk) break;
	}

	return answer;
}

int main() {
	vector<int> tmp = solution({"I 7", "I 5", "I -5", "D -1"});

	for (auto i : tmp)
		cout << i << ' ';
}


/*
�ٸ� ����� Ǯ�� -> multiset ���
(����� �˾����� ��ȸ�ϸ� ���� �������� ����� ������)
(�˾Ƶα�)

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
	vector<int> answer = {0, 0};
	set <int> pq;
	for (auto s : arguments){
		if (s[0] == 'I'){
			int num = stoi(s.substr(2, s.size()));
			pq.insert(num);
		}
		else{
			if (s[2] == '1'){
				auto it = pq.end();
				if (it != pq.begin()){
					it--;
					pq.erase(it);
				}
			}
			else{
				auto it = pq.begin();
				if (it != pq.end()){
					pq.erase(it);
				}
			}
		}
	}
	if (pq.size() > 0){
		answer[0] = *pq.rbegin();
		answer[1] = *pq.begin();
	}
	return answer;
}

*****************************************************
���⼭
	if (pq.size() > 0){
		answer[0] = *pq.rbegin();
		answer[1] = *pq.begin();
	}


	�� �κ� �˾Ƶα�

	���� �������� �����
	*(ms.begin())
	*(ms.end()) �� ����.
*****************************************************
*/