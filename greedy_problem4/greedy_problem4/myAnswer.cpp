/*
작성자 : 이상수
일시 : 2021.01.26
제목 : 조이스틱
풀이 : 위, 아래로 움직이는 경우는 정말 간단하다,
	   그냥 아스키 값 생각해서 해당 값 빼주고 작은 값 선택하면 된다.
	   (다른 풀이의 경우 map을 사용하지 않고 그냥 배열에 데칼코마니 형식을 썻다 이게 더 효율적이다)

	   좌, 우로 움직이는 게 문제인데 우선 말하자면
	   이 문제는 부분 최적해가 전체 최적해가 되지 않는다.
	   그리디 문제가 아니라는 생각이 든다...

	   그리디 문제인 만큼 탐욕스럽게 생각하면 가장 가까운 곳에 바꿀게 있다면
	   그 부분부터 갔다 오면 되는 것인데, 그렇게 하면 반례가 존재한다.

	   하지만 그렇게 풀어도 문제는 통과한다...

	   내 풀이는 탐욕법 으로 풀었으나, 이 풀이엔 반례가 존재한다.

	   다른 사람의 풀이 중 대부분이 잘못된 풀이가 있었으나
	   올바른 풀이가 하나 있어서 가지고 왔다. (아래 주석)
	   하지만 이 코드가 무슨 뜻인지는 이해를 하지 못하겠다....

	   수학적으로 계산한다는데 무슨 말인지...
제한사항 : name은 알파벳 대문자로만 이루어져 있습니다.
	       name의 길이는 1 이상 20 이하입니다.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string name) {
	int answer = 0;
	string s = "";
	map<char, int> arr;
	map<char, int> arr_r;

	for (int i = 0; i < 26; i++) {
		arr[char(65 + i)] = i;
		arr_r[char(90 - i)] = i + 1;
	}

	for (int i = 0; i < name.length(); i++)
		s += "A";

	int i = 0;
	while (s != name) {
		for (int j = 0; j < name.length() / 2 + 1; j++) {
			int n1 = i + j;
			int n2 = i - j;

			if (n1 > name.length() - 1)
				n1 = ((i + j) - name.length());

			if (n2 < 0)
				n2 = (name.length() + (i - j));

			if (s[n1] != name[n1]) {
				answer += j;
				i = n1;
				break;
			}
			else if (s[n2] != name[n2]) {
				answer += j;
				i = n2;
				break;
			}
		}

		answer += (arr[name[i]] > arr_r[name[i]] ? arr_r[name[i]] : arr[name[i]]);
		s[i] = name[i];
	}

	return answer;
}

int main() {
	cout << solution("ABABAAAAAAABA");
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
	int answer = 0;

	for (auto ch : name)
		answer += LUT[ch - 'A'];

	int len = name.length();
	int left_right = len - 1;


	// !-----------여기서 부터
	for (int i = 0; i < len; ++i) {
		int next_i = i + 1;

		while (next_i < len && name[next_i] == 'A')
			next_i++;

		left_right = min(left_right, i + len - next_i + min(i, len - next_i));
		// 여기까지 이해 불가 ------------------------------!
	}

	answer += left_right;
	return answer;
}
*/