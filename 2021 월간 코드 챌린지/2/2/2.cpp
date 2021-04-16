#include <string>
#include <vector>
#include <stack>

using namespace std;

bool chk(string s) {
	stack<char> st;
	for (int j = 0; j < s.length(); j++) {
		if (s[j] == '[' || s[j] == '{' || s[j] == '(') st.push(s[j]);
		else {
			if (st.empty()) return false;
			if (s[j] == ']') {
				if (st.top() != '[') return false;
				st.pop();
			}
			else if (s[j] == '}') {
				if (st.top() != '{') return false;
				st.pop();
			}
			else {
				if (st.top() != '(') return false;
				st.pop();
			}
		}
	}
	if (!st.empty()) return false;
	return true;
}

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.length(); i++) {
		if (chk(s)) answer++;
		string tmp = s.substr(1, s.length() - 1);
		tmp += s[0];
		s = tmp;
	}

	return answer;
}