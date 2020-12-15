#include<vector>
#include<set>
#include<unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	unordered_set<int> l(lost.begin(), lost.end()); // 정렬이 필요 없다.
	set<int> r; // 정렬이 필요하다.
	unordered_set<int> inter; // 여벌을 가지고 왔지만, 도난당한 학생들

	for (auto& x : reserve) {
		if (l.find(x) == l.end()) r.insert(x); // 여벌을 가지고 왔고, 도난을 당하지 않았다. (O(logk) = 정렬된 삽입)
		else inter.insert(x); // 여벌을 가지고 왔고, 도난을 당했다. (O(k) = 일반 삽입)
	}

	for (auto& x : inter) l.erase(x); // 여벌이 있는 도난 당한 학생들을 lost에서 지워준다.

	for (auto& x : r) {
		if (l.find(x - 1) != l.end()) l.erase(x - 1); // 빌려줘야 하는 학생이라면
		else if (l.find(x + 1) != l.end()) l.erase(x + 1);
	}

	return n - l.size();
}