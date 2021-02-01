/*
작성자 : 이상수
일시 : 2021.02.01
제목 : 단어 변환
풀이 : 이번 문제도 백트래킹과 매우 유사한 풀이이다.
       다시 생각해보니 dfs와 백트래킹은 거의 비슷하다고 볼 수 있다.
	   둘 다 모든 경우를 깊이까지 탐색했다가 처리하는것이므로 그렇다.

	   풀이는 다음과 같다
	   우선 dfs를 돌며 시작 단어와 word 속 단어 중
	   한 글자만 다른 것을 찾아 시작 단어를 해당 단어로 바꾼 다음 재귀한다.

	   그리고 한번 사용한 단어를 다시 사용하면 안되므로 
	   bool 배열을 사용하여 해당 단어를 사용 했음을 표시한다.

	   이 과정을 반복하며 target으로 변환이 가능하다면
	   now가 target과 같아지는 시기가 오는데, 
	   이 때 변환 가능한 방식이 여러개 일 수 있으므로 
	   과정을 끝내지 않고 현재 answer와 cnt를 비교하여 적은 값을 선택한다.

	   한번 사용한 단어를 후에는 사용하지 않았다고 다시 재표기 해주는 것도 꼭 해주어야 한다.
*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 51;
bool chk[51];

void dfs(string now, string target, vector<string> word, int cnt) {
	if (now == target) {
		answer = answer > cnt ? cnt : answer;
		return;
	}

	for (int i = 0; i < word.size(); i++) {
		if (chk[i]) continue;
		int diff = 0;
		for (int j = 0; j < word[i].length(); j++) {
			if (now[j] != word[i][j]) diff++;
			if (diff >= 2) break;
		}
		if (diff == 1) {
			chk[i] = true;
			dfs(word[i], target, word, cnt + 1);
			chk[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	dfs(begin, target, words, 0);
	if (answer == 51) return 0;
	return answer;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	//cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
}


/*
	추가적으로 DFS와 백트래킹은 두 사이에 관계가 있다.
	백트래킹을 하는 과정 중에 
	트리를 구성한 부분을 DFS를 수행하여 백트래킹을 완료시키는 것이었다.

	헷갈리지 말고 잘 주시하자.

			chk[i] = true;
			dfs(word[i], target, word, cnt + 1);
			chk[i] = false;
	이 부분이 중요!
*/