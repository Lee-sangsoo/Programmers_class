#include<iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

void setting() {
	m["zero"] = 1;
	m["one"] = 2;
	m["two"] = 3;
	m["three"] = 4;
	m["four"] = 5;
	m["five"] = 6;
	m["six"] = 7;
	m["seven"] = 8;
	m["eight"] = 9;
	m["nine"] = 10;
}

int solution(string s) {
	int answer = 0;
	setting();
	string cur = "";
	string total = "";
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			total += s[i];
			cur = "";
		}
		else {
			cur += s[i];
			if (m[cur] != 0) {
				total += to_string(m[cur] - 1);
				cur = "";
			}
		}
	}

	answer = stoi(total);
	return answer;
}

int main() {
	cout << solution("2three45sixseven");
}