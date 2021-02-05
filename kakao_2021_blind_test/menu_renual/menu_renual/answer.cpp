/*
작성자 : 이상수
일시 : 2021.02.05
제목 : 메뉴 리뉴얼
풀이 : 문제에서 주어지는 배열의 크기가 작아서 브루트포스를 통해 풀 수 있다.
       우선, 문제를 풀지 못해 풀이를 검색해서 확인 후에 분석했다.
	   바킹독님의 풀이를 통해 알게되었다.

	   1. 비트마스크를 통한 브루트포스 조합 구하기
	   2. map 순회시에 사용하는 방식, map 배열 사용
	   (이 두가지에 대해서는 메모장에 정리해 두었다.)

	   우선 각 손님별로 시킨 단품 메뉴들을 조합으로 구성한다.
	   해당 조합 구성을 map을 통해 얼마나 시켰나 확인한다.

	   그 후 map을 순회하며 조건을 만족하는 정답들을 찾는 과정을 거친다.

	   언제나 가장 간단한 방법은 모두 해보는 것이다.
	   가장 처음에 생각한 모든 조합을 구하나...? 라는 의문이 정답이였다.

	   모든 조합을 구하는 방식은 여러가지가 있지만, 비트마스크를 사용하는 방식이 가장
	   간단하고 짧다. (알아두자)

	   문제 자체가 2레벨인 이유가 풀이를 알고보니 정말 쉬운 문제였다.

	   아직 갈 길이 멀다...
*/
#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> freq[11];
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	// 조합 구하기
	for (auto order : orders) {
		sort(order.begin(), order.end());
		for (int i = 1; i < (1 << order.size()); i++) { // ABC -> 001 ~ 111 까지
			string menu;

			for (int j = 0; j < order.size(); j++) {
				if (i & (1 << j)) // i = 1 = 001 -> ABC 의 001 이라면 -> A (반대로 생각)
					menu += order[j];
			}

			freq[menu.size()][menu]++; // [음식 개수에 따른][조합] 개수 증가
		}
	}
	// 정답 찾기
	for (auto i : course) { // i = 2, 3, 4
		int mxfreq = 0;
		for (auto p : freq[i]) // freq[2] => AC, AB, CD, ... // freq[3] => ABC, ABD, BCD, ...
			mxfreq = max(mxfreq, p.second); // p.second = 시킨 횟수
		if (mxfreq < 2) continue; // 문제 조건에서 "최소 2명 이상의 손님으로부터 주문된 조합만" 포함하므로
		for (auto p : freq[i]) { // 2명 이상이 시켰다면 다시 한번 반복문을 돌면서 코스요리를 answer에 담는다.
			if (p.second == mxfreq) answer.push_back(p.first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	string k = "ABCDE";
	string s = "";
	for (int i = 0; i < k.size(); i++)
		if (3 & (1 << i))
			s += k[i];
	cout << s << '\n';

	map<string, int> tmp;
	tmp["A"] = 1;
	tmp["B"] = 2;
	for (auto i : tmp)
		cout << i.first << '\n';
}