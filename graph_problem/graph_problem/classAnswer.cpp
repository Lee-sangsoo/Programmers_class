#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	sort(tickets.begin(), tickets.end(), greater<vector<string>>());
	// ������ ���� = �ݹ� ������ ��ΰ� 2���� ��� ���ĺ� ������ �������� �湮�ϱ� ������
	// ������ �ϰ� ���� ����ϸ� �׻� ������ ������� ���� �����̴�.
	// ���⼭ ���������� ������ ���ÿ��� pop�� �ϸ� ������ �������� ������ �����̴�.

	unordered_map<string, vector<string>> routes;
	// [ICN] = {SFO, ATL}
	// [ATL] = {SFO, ICN}
	// [SFO] = {ATL}
	// ���� ���� �����ϱ� ���� map�� �����
	// ���ĺ� ������ ������ �̸� ������ �߱� ������ ���� ó���� �ʿ� ����

	for (int i = 0; i < tickets.size(); i++) {
		routes[tickets[i][0]].push_back(tickets[i][1]);
	}
	// key = �����  value = ������
	// ���� ���� ����ȴ�.

	vector<string> s = vector<string>{ "ICN" }; // ���� ���ô� �׻� ICN
												// stack�� ������ �Ѵ�.
	while (!s.empty()) { // DFS ����
		string airport = s.back(); // map�� find�� key���� ã�� ���̴�
		if (routes.find(airport) == routes.end() || // �׷� �װ����� ���ų�
			routes[airport].size() == 0) { // �̹� ��� �װ����� ����ߴٸ�
										   // �� ���� ���̻� �� ���� ���ٴ� ���̹Ƿ�
			answer.push_back(airport); // answer�� �־��ְ�
			s.pop_back(); // �ش� ������ �����Ѵ�.
		}
		else { // �� ���� ���� �ִٸ� (�װ����� ���� �ִٸ�)
			s.push_back(routes[airport].back()); // stack�� �ش� �������� �־��ְ�
			routes[airport].pop_back(); // �ش� �װ����� �����Ѵ�.
		}
	}
	reverse(answer.begin(), answer.end()); // ������ ���� ����� ������ �ݴ�
								// ������ stack�� ���� �� ���ĺ� �ݴ� ������ �־��� ������
	return answer;
}

int main() {
	vector<string> tmp;
	tmp = solution({ {"ICN","SFO"}, {"ICN","ATL"} , {"SFO","ATL"} ,
		{"ATL","ICN"} , {"ATL","SFO"} });
}