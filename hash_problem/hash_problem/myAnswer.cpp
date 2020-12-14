/*
작성자 : 이상수
일시 : 2020.12.14
제목 : 완주하지 못한 선수
풀이 : 해쉬 맵 사용하여 처리
제한사항 : 참여한 선수의 수는 1명 이상 100,000명 이하
	       동명이인이 있을 수 있다.
*/

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> runner;

	for (int i = 0; i < participant.size(); i++) {
		runner[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++) {
		runner[completion[i]]--;
	}

	for (int i = 0; i < participant.size(); i++) {
		if (runner[participant[i]] != 0) {
			return participant[i];
		}
	}

	return answer;
}

int main() {

}