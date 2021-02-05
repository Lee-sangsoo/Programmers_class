/*
작성자 : 이상수
일시 : 2021.01.29
제목 : 여행경로
풀이 : BFS로 문제 푸는건 많이 했는데 DFS로 푸는 건 거의 처음이다.
	   stack을 사용하여 DFS로 구현했던 문제들이 있지만, 
	   이때까지 한건 진짜 DFS가 아니였다.
	   (BFS를 그냥 stack으로 했다고 해야하나...)

	   아무튼 이 문제는 한 붓 그리기 문제로서 
	   출발지와 목적지가 숫자가 아니라 문자열로 주어지기 때문에
	   이 값들을 어떻게 저장할지 정하는게 주된 관건이였다.

	   map을 사용하여 key에 출발지 value로 vector<string>을 받는다. (목적지들)

	   자세한 풀이는 classAnswer.cpp에 주석으로 달아 두었다.

	   내 풀이도 강의에서 배운 거의 그대로이다.
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