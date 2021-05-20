#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> array) {
	vector<int> answer;

	stack<int> s;
	vector<int> ans(array.size(), -1);
	for (int i = 0; i < array.size(); i++) {
		while (!s.empty() && array[s.top()] < array[i]) {
			ans[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	stack<int> s_r;
	vector<int> ans_r(array.size(), -1);
	for (int i = array.size() - 1; i >= 0; i--) {
		while (!s_r.empty() && array[s_r.top()] < array[i]) {
			ans_r[s_r.top()] = i;
			s_r.pop();
		}
		s_r.push(i);
	}

	for (int i = 0; i < array.size(); i++) {
		if (ans[i] == -1 && ans_r[i] == -1) answer.push_back(-1);
		else {
			if (ans[i] == -1) answer.push_back(ans_r[i]);
			else if (ans_r[i] == -1) answer.push_back(ans[i]);
			else {
				if (ans[i] > ans_r[i]) answer.push_back(ans_r[i]);
				else answer.push_back(ans[i]);
			}
		}
	}

	return answer;
}