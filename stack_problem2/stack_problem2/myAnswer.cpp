/*
작성자 : 이상수
일시 : 2021.01.22
제목 : 다리를 지나는 트럭
풀이 : queue를 사용하는 문제이다.
       문제를 이해하는데 조금 시간이 걸렸다.
	   한 차가 내리자 마자 들어가는 것이 유독 헷갈렸는데
	   이는 큐에서 pop을 할 때에는 시간을 증가시키지 않으면 해결되었다.

	   나의 풀이는 다음과 같다
	   우선 트럭의 무게가 1부터 시작이기 때문에 
	   시작 전에 큐를 0으로 다리의 길이 - 1 만큼 채워준다.

	   그리고 나서 반복문을 돌며 각 트럭들이
	   다리에 올라갈 수 있다면 해당 무게를 push 하고
	   다리에 올라갈 수 없다면 0을 push 하였다.

	   반복문을 돌면서 다리에 트럭을 올리거나 못올릴 때만 시간을 증가하고
	   트럭에서 뺄때는 시간을 증가시키지 않았다.

	   모든 트럭이 다리에(큐에) 올라갔다면
	   반복문을 빠져나와 모든 트럭이 다리에서 빠질때까지
	   pop을 진행하며 시간을 1초씩 증가시켜준다.
제한사항 : bridge_length는 1 이상 10,000 이하입니다.
		   weight는 1 이상 10,000 이하입니다.
		   truck_weights의 길이는 1 이상 10,000 이하입니다.
		   모든 트럭의 무게는 1 이상 weight 이하입니다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	queue<int> q;

	for (int i = 0; i < bridge_length-1; i++)
		q.push(0);

	int cnt = 0;
	while (cnt < truck_weights.size()) {
		if (q.size() == bridge_length) { // 다리가 가득 차 있다면
			weight += q.front();
			q.pop();
		}

		if (weight >= truck_weights[cnt]) { // 트럭을 올릴 수 있다면 해당 무게
			weight -= truck_weights[cnt];
			q.push(truck_weights[cnt]);
			answer++;
			cnt++;
		}
		else { // 없다면 0
			q.push(0);
			answer++;
		}
	}

	while (!q.empty()) { // 빌 때 까지 반복
		answer++;
		q.pop();
	}

	return answer;
}

int main() {
	cout << solution(2, 10, { 7,4,5,6 });
}