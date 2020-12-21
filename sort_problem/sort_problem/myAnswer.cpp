/*
일시 : 2020.12.21
작성 : 이상수
문제 : 프로그래머스 - 가장 큰 수 (정렬)
문제 설명 : 0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 찾아라
제한사항 : numbers의 길이는 1이상 100,000 이하
		   numbers의 원소는 0이상 1,000이하
		   정답은 string으로 바꾸어 return한다.
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool check(int a, int b) {
	string c, d;
	c = to_string(a) + to_string(b);
	d = to_string(b) + to_string(a);

	return c > d; // 정렬을 할 때, 만약 3 과 30이 왔다고 가정했을 때
				  // 두 수를 이어 붙여 비교를 해보고 더 큰 쪽이 앞으로 오도록 하면 된다.
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), check);
	for (auto i : numbers) {
		answer += to_string(i);
	}
	if (answer[0] == '0') return "0";
	return answer;
}

int main() {
	cout << solution({ 0,0,0,0 });
}