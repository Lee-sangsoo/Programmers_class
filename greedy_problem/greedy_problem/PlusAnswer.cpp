#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	unordered_set<int> l(lost.begin(), lost.end()); // ������ �ʿ� ����.
	set<int> r; // ������ �ʿ��ϴ�.
	unordered_set<int> inter; // ������ ������ ������, �������� �л���

	for (auto& x : reserve) {
		if (l.find(x) == l.end()) r.insert(x); // ������ ������ �԰�, ������ ������ �ʾҴ�. (O(logk) = ���ĵ� ����)
		else inter.insert(x); // ������ ������ �԰�, ������ ���ߴ�. (O(k) = �Ϲ� ����)
	}

	for (auto& x : inter) l.erase(x); // ������ �ִ� ���� ���� �л����� lost���� �����ش�.

	for (auto& x : r) {
		if (l.find(x - 1) != l.end()) l.erase(x - 1); // ������� �ϴ� �л��̶��
		else if (l.find(x + 1) != l.end()) l.erase(x + 1);
	}

	return n - l.size();
}