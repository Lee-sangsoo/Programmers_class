/*
작성자 : 이상수
일시 : 2020.12.23
제목 : 큰 수 만들기
풀이 : 탐욕법의 뜻을 다시 생각해보며 풀이 따로 선언하거나 사용한 자료구조는 없다.
	   총 n개를 삭제 해야 한다고 할 때, 다시 말하면 총 "숫자의 길이 - n"(=m) 개를 고르는 것과 같다
	   그렇다면, 저 개수만큼 고르는 동안에 최선의 선택은 최대의 크기를 고르는 것이 가장 좋다.
	   즉, 처음 고를 수 있는 숫자는 전체 숫자의 인덱스 0부터 k까지 이다. 이 중에서 가장 큰 수를 고르면 된다.
	   그 다음은 내가 선택한 숫자의 바로 다음 인덱스 부터 k+1까지
	   이 과정을 반복하면 최대 크기의 숫자를 선택할 수 있다.
제한사항 : number는 1자리 이상, 1,000,000자리 이하인 숫자 (string)
		   k는 1 이상 number의 자릿수 미만인 자연수
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int lop = number.length() - k; // 총 반복 횟수
	int start = 0; // 시작은 0부터
	while (lop--) {
		int end = number.length() - lop; // 결국은 k, k+1, k+2, ... 가 된다.
		char maxs = '0';
		for (int i = start; i < end; i++) { // 위에서 말한 범위 안의 가장 큰 수를 찾는다.
			if (maxs < number[i]) {
				maxs = number[i];
				start = i + 1;
			}
		}
		answer += maxs;
	}

	return answer;
}

int main() {
	cout << solution("4177252841", 4);
}