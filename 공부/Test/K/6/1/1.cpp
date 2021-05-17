#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string inputString) {
	int answer = 0;
	bool correct = true;
	stack<char> s;
	for (int i = 0; i < inputString.length(); i++) {
		if (inputString[i] == '(' || inputString[i] == '[' || inputString[i] == '{' || inputString[i] == '<')
			s.push(inputString[i]);
		else {
			if (inputString[i] == ')') {
				if (s.top() == '(') {
					s.pop();
					answer++;
				}
				else {
					answer = -1 * i;
					correct = false;
					break;
				}
			}
			else if (inputString[i] == ']') {
				if (s.top() == '[') {
					s.pop();
					answer++;
				}
				else {
					answer = -1 * i;
					correct = false;
					break;
				}
			}
			else if (inputString[i] == '}') {
				if (s.top() == '{') {
					s.pop();
					answer++;
				}
				else {
					answer = -1 * i;
					correct = false;
					break;
				}
			}
			else if (inputString[i] == '>') {
				if (s.top() == '<') {
					s.pop();
					answer++;
				}
				else {
					answer = -1 * i;
					correct = false;
					break;
				}
			}
		}
	}
	if (correct && !s.empty()) answer = -1 * (inputString.length() - 1);

	return answer;
}