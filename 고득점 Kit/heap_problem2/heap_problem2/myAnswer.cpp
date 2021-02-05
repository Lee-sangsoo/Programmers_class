/*
일시 : 2021.01.13
작성 : 이상수
문제 : 프로그래머스 - 디스크 컨트롤러 (힙)
문제 설명 : 한 번에 하나의 작업을 수행 할 수 있는 하드디스크에 주어진 업무들을
            작업이 요청되는 시점, 작업의 소요시간 형식으로 주어질 때,
			모든 작업이 끝나는 평균 "실행 완료 시간"의 최소값을 찾아라
			(실행 완료 시간 = 대기시간 + 실행시간)
제한사항 : jobs의 길이는 1 이상 500 이하
		   각 작업에 대해 작업이 요청되는 시간은 0 이상 1,000 이하
		   각 작업에 대해 작업의 소요시간은 1 이상 1,000 이하입니다.
		   하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리합니다.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool chk[501]; // jobs의 내용이 힙에 들어갔는지 안갔는지 확인을 위한 bool 배열

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	int sec = 0; // 현재 시간을 재기 위한 변수
	int n = 0; // 총 몇개를 진행 하였는지 확인을 위한 변수 -> jobs.size()와 같아지면 반복을 끝낸다.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	while (n < jobs.size()) {
		for (int i = 0; i < jobs.size(); i++) {
			if (sec >= jobs[i][0] && !chk[i]) {
				pq.push(make_pair(jobs[i][1], jobs[i][0])); // pair에 인덱스 순서를 바꾼 이유는 greater의 비교가 first 우선이기 때문이다.
				chk[i] = true;
			}
		} // jobs를 돌면서 아직 참조하지 않은 곳(chk[i]가 false인 부분)을 찾아 해당 작업이
		  // 현재 시간에 실행이 가능한 작업인지를 확인하여 힙에 넣어준다.

		if (pq.empty()) {
			sec++;
			continue;
		} // 힙이 비었다면 현재 도착한 작업이 없다는 뜻이므로 시간을 1초 증가 시키고 다시 반복문을 실행한다.
		answer += (sec - pq.top().second) + pq.top().first; // 실행 완료 시간들을 더해간다.
		sec += pq.top().first; // 현재 시간의 증가는 현재 시간에 실행한 작업의 실행시간만 더해주면 된다.
		pq.pop();
		n++;
	}
	answer /= jobs.size(); // 실행 완료 시간을 모두 더한 값을 작업의 수로 나눠서 리턴한다.
	return answer;
}

int main() {
	cout << solution({ {10, 10}, {30, 10}, {50,2}, {51, 2} }); // = 6
}