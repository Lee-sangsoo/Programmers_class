/*
일시 : 2020.12.15
작성 : 이상수
문제 : 프로그래머스 - 체육복 (그리디)
문제 설명 : n명의 학생들에게 기본적으로 체육복이 있고, 체육복을 잃어버린 학생과 여분의 체육복을 가지고 있는 
			학생이 있을 때, n번째 학생이 체육복을 잃어버렸고, 체육복을 n-1번째 학생 혹은 n+1번째 학생에게서 빌리는것이
			가능할 때, 최대한 많은 학생이 체육수업을 들을 때의 학생 수는 몇 명인가
제한사항 : 전체 학생의 수는 2명 이상 30명 이하
		   도난당한 학생의 수는 1명 이상 n명 이하
		   여분의 체육복을 가져온 학생은 1명 이상 n명 이하, 중복으로 가지고 있는 학생은 없다.
		   여분을 가진 학생이 도난을 당하는 경우도 있다.
*/


#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> now(n + 1); // n명의 학생의 체육복 갯수를 표현하기 위한 now 벡터 선언

	for (int i = 1; i <= n; i++) { // lost와 reserve가 가지고 있는 수가 1부터 n까지 이므로 범위를 1부터 시작으로 맞춰준다.
		now[i] = 1;
	} // 모든 학생의 시작은 모두 한벌씩 가지고 있는 것에서 시작 (체육복 수 = 1)

	for (auto i : lost) now[i]--;     // 잃어버린 학생들의 체육복 수를 1씩 감소

	for (auto i : reserve) now[i]++;  // 여분이 있는 학생들의 체육복 수를 1씩 증가

	for (int i = 1; i <= n; i++) {
		if (now[i] >= 1) { // 1보다 크거나 같은 학생은 체육복이 있다는 뜻이므로 answer의 값 증가
			answer++;
			continue;
		}
		else { // 1보다 작다면 체육복이 없다는 뜻이므로
			if (now[i - 1] > 1 && i > 1) { // 이 전의 학생
				now[i - 1]--; // 중복으로 빌려주는 경우를 막기 위해 감소
				now[i]++;
				answer++;
				continue;
			}
			else if (now[i + 1] > 1 && i+1 < n + 1) { // 이 후의 학생
				now[i + 1]--; 
				now[i]++;
				answer++;
				continue;
			} // 에게서 자기 자신의 것 보다 개수가 많은 학생이 있다면(2) 빌려온다
		}
	} 

	return answer;
}