#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <set>

using namespace std;

stack<int> st;
list<int> li;
set<int> se;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";

	for (int i = 0; i < n; i++)
		li.push_back(i);

	for (int i = 0; i < n; i++)
		se.insert(i);
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i][0] == 'D') {
			int x = stoi(cmd[i].substr(2));
			k += x;
			if (k >= se.size()) k = se.size() - 1;
		}
		else if (cmd[i][0] == 'U') {
			int x = stoi(cmd[i].substr(2));
			k -= x;
			if (k < 0) k = 0;
		}
		// 행 삭제 (선택은 한칸 밑으로 // 마지막 가리키면 한칸 위로)
		else if (cmd[i][0] == 'C') {
			set<int>::iterator it = se.begin();
			advance(it, k);
			st.push(*it);
			se.erase(it);
			if (k == li.size()) k--;

		}
		// 행 복구 (최근에 지운 행 복구 // 선택은 유지)
		else if (cmd[i][0] == 'Z') {
			int x = st.top();
			st.pop();
			set<int>::iterator it2 = se.begin();
			advance(it2, k);
			if (*it2 > x) k++;

			se.insert(x);
		}
	}
	
	vector<bool> chk(n, false);
	for (auto it = se.begin(); it != se.end(); it++) 
		chk[*it] = true;
	
	for (int i = 0; i < n; i++) {
		if (chk[i]) answer += "O";
		else answer += "X";
	}
	return answer;
}

int main() {
	//cout << solution(4, 0, { "C", "Z", "C", "C" });
	cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });
}

/*
list<int>::iterator it = li.begin();
			advance(it, k);
			li.erase(it);
*/

// "D 2","C","U 3","C","D 4","C","U 2","Z","Z"

/*
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i][0] == 'D') {
			int x = stoi(cmd[i].substr(2));
			k += x;
			if (k >= li.size()) k = li.size() - 1;
		}
		else if (cmd[i][0] == 'U') {
			int x = stoi(cmd[i].substr(2));
			k -= x;
			if (k < 0) k = 0;
		}
		// 행 삭제 (선택은 한칸 밑으로 // 마지막 가리키면 한칸 위로)
		else if (cmd[i][0] == 'C') {
			list<int>::iterator it = li.begin();
			advance(it, k);
			st.push(*it);
			li.erase(it);
			if (k == li.size()) k--;

		}
		// 행 복구 (최근에 지운 행 복구 // 선택은 유지)
		else if (cmd[i][0] == 'Z') {
			int x = st.top();
			st.pop();
			list<int>::iterator it2 = li.begin();
			advance(it2, k);
			if (*it2 > x) k++;

			list<int>::iterator it;
			for (it = li.begin(); it != li.end(); it++) {
				if (*it > x) {
					break;
				}
			}
			li.insert(it, x);

		}
	}
	*/