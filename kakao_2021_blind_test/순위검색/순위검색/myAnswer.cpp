/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.08
���� : ���� �˻�
Ǯ�� : ������ Ǯ�̴� ó�� ���ø� ����� �´�.
       ������, īī�� �ڵ� �׽�Ʈ ������ ��κ� �̷��� ������
	   ���ڿ��� �ٷ�� �Լ��� ���� �˼��� Ǯ�Ⱑ ���������°Ͱ���.
	   �̹� ���������� map�� ����Ͽ� value ������ vector�� �ִ� ����� �¾Ҵ�.

	   ������, ���� map�� �迭�� �����Ͽ� �� ��츦 0 1 2 3 ���� �ٲپ� ó���Ͽ���
	   �̴� ���ڿ��� �ٷ��� �ȴٸ� ���ʿ��� �ൿ�̾���.

	   �ٽ� ���� ���� [java][back][junior][chicken] = {...} �� ���� ó���ߴٸ�,
	   ���ڿ��� �� �ٷ�ô� �ٸ��е���
	   [javavackjuniorchicken] = {...} �� ���� ó���ϼ̴�.

	   �� ����� �� ���⵵ ���� �ٷ�⵵ ������̴�.

	   �߰������� �� ������ ���ǿ��� �� �κ��� ������� �ʴ� ��쵵 �ֱ� ������
	   �� �ڵ��� 60 ~ 79 �ٰ� ���� ������� �ʴ� �͵��� ó���� �ʿ��ϴ�.

	   �� ���� bitMask�� �̿��� ó���� �����ϰ� ó���ϴ���....

	   otherAnswer.cpp �� ���� ������, �˾ƾ� �ϴ� �͵��� ������ �ξ���
	   �߰��� �޸��忡 lower_bound ���� �����Ͽ���.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	map<int, vector<int>> infomation[4][3][3];
	vector<int> answer;
	for (int i = 0; i < info.size(); i++) {
		vector<string> st;
		string word = "";
		for (int j = 0; j < info[i].length(); j++) {
			if (info[i][j] != ' ') {
				word += info[i][j];
			}
			else {
				st.push_back(word);
				word.clear();
			}
		}
		st.push_back(word);
		
		int n1 = 0;
		if (st[0] == "java") n1 = 1;
		else if (st[0] == "python") n1 = 2;

		int n2 = 0;
		if (st[1] == "frontend") n2 = 1;
		
		int n3 = 0;
		if (st[2] == "senior") n3 = 1;

		int n4 = 0;
		if (st[3] == "pizza") n4 = 1;

		infomation[n1][n2][n3][n4].push_back(stoi(st[4]));

		infomation[3][n2][n3][n4].push_back(stoi(st[4]));
		infomation[n1][2][n3][n4].push_back(stoi(st[4]));
		infomation[n1][n2][2][n4].push_back(stoi(st[4]));
		infomation[n1][n2][n3][2].push_back(stoi(st[4]));

		infomation[3][2][n3][n4].push_back(stoi(st[4]));
		infomation[3][n2][2][n4].push_back(stoi(st[4]));
		infomation[3][n2][n3][2].push_back(stoi(st[4]));
		infomation[n1][2][2][n4].push_back(stoi(st[4]));
		infomation[n1][2][n3][2].push_back(stoi(st[4]));
		infomation[n1][n2][2][2].push_back(stoi(st[4]));

		infomation[3][2][2][n4].push_back(stoi(st[4]));
		infomation[3][2][n3][2].push_back(stoi(st[4]));
		infomation[3][n2][2][2].push_back(stoi(st[4]));
		infomation[n1][2][2][2].push_back(stoi(st[4]));

		infomation[3][2][2][2].push_back(stoi(st[4]));
		// �� ���ǿ��� �ٷ��� ���� 3, 2, 2, 2 �� ���� "-"(������� ����)�� ���Ѵ�.
	}
	 
	for (int n1 = 0; n1 < 4; n1++)
		for (int n2 = 0; n2 < 3; n2++)
			for (int n3 = 0; n3 < 3; n3++)
				for (int n4 = 0; n4 < 3; n4++)
					sort(infomation[n1][n2][n3][n4].begin(), infomation[n1][n2][n3][n4].end());

	for (int i = 0; i < query.size(); i++) {
		vector<string> st;
		string word = "";
		for (int j = 0; j < query[i].length(); j++) {
			if (query[i][j] != ' ') {
				word += query[i][j];
			}
			else {
				if (word != "and") st.push_back(word);
				word.clear();
			}
		}
		st.push_back(word);

		int n1 = 0;
		if (st[0] == "java") n1 = 1;
		else if (st[0] == "python") n1 = 2;
		else if (st[0] == "-") n1 = 3;

		int n2 = 0;
		if (st[1] == "frontend") n2 = 1;
		else if (st[1] == "-") n2 = 2;

		int n3 = 0;
		if (st[2] == "senior") n3 = 1;
		else if (st[2] == "-") n3 = 2;

		int n4 = 0;
		if (st[3] == "pizza") n4 = 1;
		else if (st[3] == "-") n4 = 2;

		vector<int> tmp = infomation[n1][n2][n3][n4];
		int target = stoi(st[4]);

		//�̺� Ž�� ���� ���� (�ٵ� �̷��� �ϸ� ������ ����... ����...)
		/*
		int l = 0;
		int r = tmp.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (tmp[mid] < target) {
				l = mid + 1;
			}
			else r = mid;
		}
		answer.push_back(tmp.size() - l);
		*/

		// ���̺귯�� �Լ� ���
		answer.push_back(tmp.end() - lower_bound(tmp.begin(), tmp.end(), target));
	}
	return answer;
}

int main() {
	vector<int> tmp = solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" },
		{ "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
	for(auto i : tmp)
		cout << i << ' ';
}