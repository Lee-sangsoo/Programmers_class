#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer;

	for (int i = 0; i < s.size(); i++) {
		priority_queue<string, vector<string>, greater<string>> pq;
		string now = s[i];
		string tmp = "";
		string mins = "";
		int cur = 2;
		for (int j = 0; j < now.length(); j++) {
			if(tmp.length() == 3)
				tmp = tmp.substr(1);
			tmp += now[j];
			if (tmp == "110") {
				cur = j;
				break;
			}
		}
		string s = "";
		s += now.substr(0, cur - 2);
		s += now.substr(cur + 1);
		for (int j = 0; j < s.length(); j++) {
			string st = s.substr(0, j);
			st += "110";
			st += s.substr(j);
			pq.push(st);
		}
		answer.push_back(pq.top());
	}
	
	return answer;
}

int main() {
	vector<string> tmp = solution({ "1110", "100111100", "0111111010" });
	for (auto i : tmp)
		cout << i << ' ';
}