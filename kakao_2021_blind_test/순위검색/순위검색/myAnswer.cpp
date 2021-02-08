/*
작성자 : 이상수
일시 : 2021.02.08
제목 : 순위 검색
풀이 : 문제의 풀이는 처음 떠올린 방법이 맞다.
       하지만, 카카오 코딩 테스트 문제가 대부분 이런것 같은데
	   문자열을 다루는 함수를 많이 알수록 풀기가 수월해지는것같다.
	   이번 문제에서도 map을 사용하여 value 값으로 vector를 주는 방식은 맞았다.

	   하지만, 나는 map을 배열로 선언하여 각 경우를 0 1 2 3 으로 바꾸어 처리하였고
	   이는 문자열을 다룰줄 안다면 불필요한 행동이었다.

	   다시 말해 나는 [java][back][junior][chicken] = {...} 과 같이 처리했다면,
	   문자열을 잘 다루시는 다른분들은
	   [javavackjuniorchicken] = {...} 과 같이 처리하셨다.

	   이 방법이 더 보기도 좋고 다루기도 쉬울것이다.

	   추가적으로 이 문제는 조건에서 각 부분을 고려하지 않는 경우도 있기 때문에
	   내 코드의 60 ~ 79 줄과 같이 고려하지 않는 것들의 처리도 필요하다.

	   이 또한 bitMask를 이용한 처리로 간단하게 처리하더라....

	   otherAnswer.cpp 에 내가 몰랐던, 알아야 하는 것들을 정리해 두었고
	   추가로 메모장에 lower_bound 등을 정리하였다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	map<int, vector<int>> infomation[4][3][3];
	vector<int> answer;
	for (int i = 0; i < info.size(); i++) {
		vector<string> st;
		string word = "";
		for (int j = 0; j < info[i].length(); j++) {
			if (info[i][j] != ' ') {
				word += info[i][j];
			}
			else {
				st.push_back(word);
				word.clear();
			}
		}
		st.push_back(word);
		
		int n1 = 0;
		if (st[0] == "java") n1 = 1;
		else if (st[0] == "python") n1 = 2;

		int n2 = 0;
		if (st[1] == "frontend") n2 = 1;
		
		int n3 = 0;
		if (st[2] == "senior") n3 = 1;

		int n4 = 0;
		if (st[3] == "pizza") n4 = 1;

		infomation[n1][n2][n3][n4].push_back(stoi(st[4]));

		infomation[3][n2][n3][n4].push_back(stoi(st[4]));
		infomation[n1][2][n3][n4].push_back(stoi(st[4]));
		infomation[n1][n2][2][n4].push_back(stoi(st[4]));
		infomation[n1][n2][n3][2].push_back(stoi(st[4]));

		infomation[3][2][n3][n4].push_back(stoi(st[4]));
		infomation[3][n2][2][n4].push_back(stoi(st[4]));
		infomation[3][n2][n3][2].push_back(stoi(st[4]));
		infomation[n1][2][2][n4].push_back(stoi(st[4]));
		infomation[n1][2][n3][2].push_back(stoi(st[4]));
		infomation[n1][n2][2][2].push_back(stoi(st[4]));

		infomation[3][2][2][n4].push_back(stoi(st[4]));
		infomation[3][2][n3][2].push_back(stoi(st[4]));
		infomation[3][n2][2][2].push_back(stoi(st[4]));
		infomation[n1][2][2][2].push_back(stoi(st[4]));

		infomation[3][2][2][2].push_back(stoi(st[4]));
		// 위 조건에서 다루지 않은 3, 2, 2, 2 는 각각 "-"(고려하지 않음)을 뜻한다.
	}
	 
	for (int n1 = 0; n1 < 4; n1++)
		for (int n2 = 0; n2 < 3; n2++)
			for (int n3 = 0; n3 < 3; n3++)
				for (int n4 = 0; n4 < 3; n4++)
					sort(infomation[n1][n2][n3][n4].begin(), infomation[n1][n2][n3][n4].end());

	for (int i = 0; i < query.size(); i++) {
		vector<string> st;
		string word = "";
		for (int j = 0; j < query[i].length(); j++) {
			if (query[i][j] != ' ') {
				word += query[i][j];
			}
			else {
				if (word != "and") st.push_back(word);
				word.clear();
			}
		}
		st.push_back(word);

		int n1 = 0;
		if (st[0] == "java") n1 = 1;
		else if (st[0] == "python") n1 = 2;
		else if (st[0] == "-") n1 = 3;

		int n2 = 0;
		if (st[1] == "frontend") n2 = 1;
		else if (st[1] == "-") n2 = 2;

		int n3 = 0;
		if (st[2] == "senior") n3 = 1;
		else if (st[2] == "-") n3 = 2;

		int n4 = 0;
		if (st[3] == "pizza") n4 = 1;
		else if (st[3] == "-") n4 = 2;

		vector<int> tmp = infomation[n1][n2][n3][n4];
		int target = stoi(st[4]);

		//이분 탐색 직접 구현 (근데 이렇게 하면 에러가 난다... 왜지...)
		/*
		int l = 0;
		int r = tmp.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (tmp[mid] < target) {
				l = mid + 1;
			}
			else r = mid;
		}
		answer.push_back(tmp.size() - l);
		*/

		// 라이브러리 함수 사용
		answer.push_back(tmp.end() - lower_bound(tmp.begin(), tmp.end(), target));
	}
	return answer;
}

int main() {
	vector<int> tmp = solution({ "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" },
		{ "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" });
	for(auto i : tmp)
		cout << i << ' ';
}