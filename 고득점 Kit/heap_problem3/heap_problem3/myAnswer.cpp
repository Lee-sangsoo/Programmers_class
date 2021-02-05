/*
작성자 : 이상수
일시 : 2021.01.21
제목 : 이중우선순위큐
풀이 : 정석적인 풀이는 multiset을 사용하는 방식인데, 처음에 다 짜서 해놓고는
       multiset을 순회하는 방식과 순회하며 값을 가져오는 방법을 몰랐다.
	   다른 사람의 풀이를 통해 해당 방법을 알았다.

	   내가 푼 방식은 좀 난잡하기도 하고 힘들다.
	   
	   우선 우선순위 큐를 2개 만들어서
	   하나는 최대값 힙
	   다른 하나는 최소값 힙 으로 만든다.

	   그리고 나서 각 명령어에 맞게 넣고
	   삭제의 경우 1이면 최대값 힙만 pop
	              -1이면 최소값 힙만 pop
	   하여 최종 결과를 가져오고

	   각 값들을 vector에 또 넣어준다.
	   그리고 한쪽을 정렬하여 
	   vector를 순회하며 값이 일치하면 가져오고 break 하는 방식을 사용했다.

	   2개의 우선순위 큐를 사용하다 보니, 값이 있는지 없는지 파악하는게
	   힘이 들었다.
	   그래서 두 자료구조 중 하나라도 비었거나 
	   명령어 I의 횟수와 D의 횟수가 같거나 D가 큰 경우는 {0, 0}을 반환했다.
제한사항 : number는 1자리 이상, 1,000,000자리 이하인 숫자 (string)
		   k는 1 이상 number의 자릿수 미만인 자연수
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
다른 사람의 풀이 -> multiset 사용
(방식은 알았으나 순회하며 값을 가져오는 방식을 몰랐음)
(알아두기)

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
여기서
	if (pq.size() > 0){
		answer[0] = *pq.rbegin();
		answer[1] = *pq.begin();
	}


	이 부분 알아두기

	값을 가져오는 방법은
	*(ms.begin())
	*(ms.end()) 와 같다.
*****************************************************
*/