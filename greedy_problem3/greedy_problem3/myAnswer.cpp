/*
작성자 : 이상수
일시 : 2021.01.22
제목 : 구명보트
풀이 : 탐욕법 말 그대로 우선적으로 넣을 수 있는 사람부터 넣으면 된다.
       처음 푼 방법은 우선 벡터를 정렬하고 
	   2중 반복문을 통해 가장 "가벼운" 사람과 가장 무거운 사람 중 
	   함께 태울 수 있는 사람을 찾아서 태워 보내는 방식을 사용 하였으나,
	   이 방식은 효율성 테스트에서 실패했다. (시간 초과)

	   이를 해결하기 위해 고민에  고민을 하다가
	   "가벼운 순서" 대로 정렬을 하고 있다는 생각이 머리를 지배하고 있었다.
	   이를 다르게 생각해서 "무거운 순서" 대로 정렬을 하면 안되나?
	   라는 생각이 들었다.
	   
	   가장 무거운 사람이 타고 나서 가장 가벼운 사람이 탈 수 있다면
	   이는 태워 보낼 수 있기 때문이다.

	   이 방식을 구현한게 아래 코드이다.
제한사항 : 무인도에 갇힌 사람은 1명 이상 50,000명 이하
           각 사람의 몸무게는 40kg 이상 240kg 이하
		   구명보트의 무게 제한은 40kg 이상 240kg 이하
		   사람들을 구출 할 수 없는 경우는 주어지지 않는다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end(), greater<int>()); // 무거운 사람부터 정렬

	int cnt = 0; // 가벼운 사람 중 탄 사람을 제외하기 위해 사용
	for (int i = 0; i < people.size() - cnt; i++) { // 아래에서 cnt 값을 연산하여 그 범위를 조정한다.
		if (people[i] + people[people.size() - 1 - cnt] <= limit) { // 보트에 2명이 탈 수 있다면
			cnt++; // cnt 증가
		}
		answer++;
	}
	
	return answer;
}

int main() {
	cout << solution({ 10,20,30,40,50,60,70,80,90 }, 100); // 정답 = 5
}