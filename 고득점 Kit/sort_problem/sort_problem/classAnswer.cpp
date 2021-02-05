#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a, int b) {
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(b) + to_string(a);
	return s1 > s2;
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), cmp); // O(nlogn) 보다 낮은 알고리즘은 존재할 수 없다.
	for (auto& i : numbers)
		answer += to_string(i);
	return answer[0] == '0' ? "0" : answer;
}

// 동일한 알고리즘을 사용하였고, 조금 더 깔끔한 코딩 스타일로 바뀌었다.