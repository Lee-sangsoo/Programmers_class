/*
작성자 : 이상수
일시 : 2020.12.14
제목 : 완주하지 못한 선수
풀이 : 해쉬 맵 사용하여 처리
제한사항 : 참여한 선수의 수는 1명 이상 100,000명 이하
		   동명이인이 있을 수 있다.
*/

// 강의 에서의 풀이

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> runner;

	for (auto &i : participant) runner[i]++;

	for (auto &i : completion) runner[i]--;

	for (auto &i : runner) {
		if (i.second != 0) {
			return i.first;
		}
	}

	return answer;
}

int main() {

}