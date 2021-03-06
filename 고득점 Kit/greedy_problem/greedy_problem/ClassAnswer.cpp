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

/*
탐욕법 : 알고리즘의 각 단계에서 그 순간에 최적이라고 생각되는 것을 선택하는 알고리즘
	문제 유형 = 현재의 선택이 마지막 해답의 최적성을 해치지 않을 때 (지금 좋은게 끝에도 좋다)
가능성 확인 : "빌려줄 학생들을 "정해진 순서"로 살펴야 하고, 
									"정해진 순서"에 따라 우선하여 빌려줄 방향을 정해야 한다.

문제 풀이 : 학생의 수는 기껏해야 30명
			학생 수만큼 배열을 확보하고, 여기에 각자 가지고 있는 체육복의 수를 기록
			-> 번호 순서대로 "스캔" 하면서 빌려줄 관계를 정한다.

			내 풀이에서는 1이상 n이하의 범위를 고려하여 각 조건문에 처리하였다.
				하지만, 0번째에 1 n+1번째에 1 의 값을 넣어두면 내 알고리즘에서도 1보다 크지 않기 때문에 바로 처리가 가능하다.

			처리하는 방식에 "순서대로" 하는 것이 중요하다
			
			이 방식은 O(n)의 시간이 걸린다.

			내 방식은 체육복이 없는 학생이 있는 학생들에게 묻는 방식이라면
			수업의 방식은 체육복의 여벌이 있는 학생들이 없는 학생들을 찾아 묻는 방식이다.

			둘다 이 방식에서는 비슷하지만, 만약 전체 학생의 수가 매우크다면 수업의 방식이 더 좋아지는 경우가 생긴다.

만약? : 전체 학생 수는 매우 크고, 여벌의 체육복을 가져온 학생의 수는 매우 작다면?
		-> O(n)의 방식보다 O(k)의 수업의 방식이 더욱 좋다
		-> 여벌을 가져온 학생들을 "정렬" 하고, 없는 학생들을 찾아서 빌려주며 해당 벡터에서 제거한다.
		-> 이렇게 벡터를 제거해 가며, 여벌이 있는 학생들이 모두 사라졌을 때, n - lost벡터의 크기 로 정답을 도출한다.
*/

/*
1. vector<int> now(n+2, 1) --> n+2의 크기 벡터를 모두 1로 초기화 한다.
2. 없는 학생을 찾는게 더 간단하다 (아마도 있는 학생 찾는것도 간단하게 가능하다)
3. 
*/


#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> now(n + 1);

	for (int i = 1; i <= n; i++) {
		now[i] = 1;
	}

	for (auto i : lost) now[i]--;

	for (auto i : reserve) now[i]++;

	for (int i = 1; i <= n; i++) {
		if (now[i - 1] == 0 && now[i] == 2)
			now[i - 1] = now[i] = 1;
		else if (now[i] == 2 && now[i + 1] == 0)
			now[i] = now[i + 1] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (now[i] > 0) answer++;
	return answer;
}