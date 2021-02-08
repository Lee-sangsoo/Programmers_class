/*
작성자 : 이상수
일시 : 2021.02.08
제목 : 신규 아이디 추천
풀이 : 1번 문제로 가장 간단한 구현 문제이다.
       문제를 풀면서 문자열과 관련된 라이브러리 함수들을 안다면 정말 짧은 코드로 풀이가 가능하다.
	   객체 지향적 풀이로 풀게 되었다. (solution에 모두 넣으면 너무 보기 힘들것 같아서)

	   문제의 풀이는 시키는대로만 구현하면 되는 문제여서 크게 어렵지 않게 풀 수 있었다.

	   otherAnswer.cpp 에 다른 사람의 문자열 라이브러리 함수 사용 풀이가 있다. 
	   그걸 확인해서 익혀두자. (유용하다)
*/
#include <iostream>
#include <string>

using namespace std;

string first_step(string id) {
	string low = id;
	for (int i = 0; i < low.length(); i++) {
		low[i] = tolower(low[i]);
	}
	return low;
}

string second_step(string id) {
	string chk = "";
	for (int i = 0; i < id.length(); i++) {
		if (isdigit(id[i]) || islower(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.')
			chk += id[i];
	}
	return chk;
}

string third_step(string id) {
	string chk = "";
	bool checkPoint = false;
	for (int i = 0; i < id.length(); i++) {
		if (id[i] == '.') {
			if (!checkPoint) {
				chk += id[i];
				checkPoint = true;
			}
		}
		else {
			checkPoint = false;
			chk += id[i];
		}
	}
	return chk;
}

string fourth_step(string id) {
	string chk = "";
	if (id[0] != '.') chk += id[0];
	for (int i = 1; i < id.length() - 1; i++) {
		chk += id[i];
	}
	if (id[id.length() - 1] != '.') chk += id[id.length() - 1];
	return chk;
}

string fifth_step(string id) {
	if (id == "") return "a";
	else return id;
}

string sixth_step(string id) {
	string chk = "";
	if (id.length() < 16) return id;
	for (int i = 0; i < 14; i++)
		chk += id[i];
	if (id[14] != '.') chk += id[14];
	return chk;
}

string seventh_step(string id) {
	string chk = id;
	if (id.length() > 2) return id;
	while (chk.length() < 3) {
		chk += id[id.length() - 1];
	}
	return chk;
}

string solution(string new_id) {
	string answer = "";
	answer = first_step(new_id);
	answer = second_step(answer);
	answer = third_step(answer);
	answer = fourth_step(answer);
	answer = fifth_step(answer);
	answer = sixth_step(answer);
	answer = seventh_step(answer);
	return answer;
}

int main() {
	cout << solution("...!@BaT#*..y.abcdefghijklm");
}