#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	sort(tickets.begin(), tickets.end(), greater<vector<string>>());
	// 정렬의 이유 = 반문 가능한 경로가 2개인 경우 알파벳 순서가 빠른곳을 방문하기 때문에
	// 정렬을 하고 나서 사용하면 항상 조건의 순서대로 가기 때문이다.
	// 여기서 내림차순인 이유는 스택에서 pop을 하면 순서가 역순으로 나오기 때문이다.

	unordered_map<string, vector<string>> routes;
	// [ICN] = {SFO, ATL}
	// [ATL] = {SFO, ICN}
	// [SFO] = {ATL}
	// 위와 같이 저장하기 위해 map을 사용함
	// 알파벳 순서는 위에서 미리 정렬을 했기 때문에 따로 처리가 필요 없음

	for (int i = 0; i < tickets.size(); i++) {
		routes[tickets[i][0]].push_back(tickets[i][1]);
	}
	// key = 출발지  value = 목적지
	// 위와 같이 저장된다.

	vector<string> s = vector<string>{ "ICN" }; // 시작 도시는 항상 ICN
												// stack의 역할을 한다.
	while (!s.empty()) { // DFS 시작
		string airport = s.back(); // map의 find는 key값을 찾는 것이다
		if (routes.find(airport) == routes.end() || // 그런 항공권이 없거나
			routes[airport].size() == 0) { // 이미 모든 항공권을 사용했다면
										   // 이 말은 더이상 갈 곳이 없다는 말이므로
			answer.push_back(airport); // answer에 넣어주고
			s.pop_back(); // 해당 공항을 제외한다.
		}
		else { // 갈 곳이 남아 있다면 (항공권이 남아 있다면)
			s.push_back(routes[airport].back()); // stack에 해당 목적지를 넣어주고
			routes[airport].pop_back(); // 해당 항공권을 삭제한다.
		}
	}
	reverse(answer.begin(), answer.end()); // 정답은 현재 저장된 순서의 반대
								// 위에서 stack에 넣을 때 알파벳 반대 순서로 넣었기 때문에
	return answer;
}

int main() {
	vector<string> tmp;
	tmp = solution({ {"ICN","SFO"}, {"ICN","ATL"} , {"SFO","ATL"} ,
		{"ATL","ICN"} , {"ATL","SFO"} });
}