/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.29
���� : ������
Ǯ�� : BFS�� ���� Ǫ�°� ���� �ߴµ� DFS�� Ǫ�� �� ���� ó���̴�.
	   stack�� ����Ͽ� DFS�� �����ߴ� �������� ������, 
	   �̶����� �Ѱ� ��¥ DFS�� �ƴϿ���.
	   (BFS�� �׳� stack���� �ߴٰ� �ؾ��ϳ�...)

	   �ƹ�ư �� ������ �� �� �׸��� �����μ� 
	   ������� �������� ���ڰ� �ƴ϶� ���ڿ��� �־����� ������
	   �� ������ ��� �������� ���ϴ°� �ֵ� �����̿���.

	   map�� ����Ͽ� key�� ����� value�� vector<string>�� �޴´�. (��������)

	   �ڼ��� Ǯ�̴� classAnswer.cpp�� �ּ����� �޾� �ξ���.

	   �� Ǯ�̵� ���ǿ��� ��� ���� �״���̴�.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	sort(tickets.begin(), tickets.end(), greater<vector<string>>());
	unordered_map<string, vector<string>> m;
	for (int i = 0; i < tickets.size(); i++)
		m[tickets[i][0]].push_back(tickets[i][1]);
	vector<string> s = { "ICN" };
	while (!s.empty()) {
		string station = s.back();
		if (m.find(station) == m.end() || m[station].size() == 0) {
			answer.push_back(station);
			s.pop_back();
		}
		else {
			s.push_back(m[station].back());
			m[station].pop_back();
		}
	}
	reverse(answer.begin(), answer.end());
	return answer;
}