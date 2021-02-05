/*
작성자 : 이상수
일시 : 2021.02.01
제목 : 단어 변환
풀이 : 문제 풀이는 DFS나 BFS 보다는 백트래킹에 가깝다고 볼 수 있다.
       모든 경우를 돌아보고 답이 되는것에만 추가를 해주기 때문에
	   처음 DFS/BFS 카테고리의 문제라고 해서 그쪽으로만 생각한게 착각이였다.

	   문제의 풀이는 간단하다.
	   재귀적으로 함수를 돌면서 한번은 + 다른 한번은 - 를 해주어서
	   모든 숫자를 다 썼을 때 나오는 값이
	   target과 같으면 정답을 1 추가해주는 방식을 사용했다.

	   아래에 있는 풀이는 백트래킹을 할 때 비트연산을 하는 방식이다.
	   더 쉽다고 할 수도 있고 아닐수도 있다. (알아는 두자)
*/
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int target, int cnt, vector<int> n, int sum) {
	if (cnt == n.size()) {
		if (sum == target) answer++;
		return;
	}

	dfs(target, cnt + 1, n, sum + n[cnt]);
	dfs(target, cnt + 1, n, sum - n[cnt]);
}

int solution(vector<int> numbers, int target) {
	dfs(target, 0, numbers, 0);
	return answer;
}

int main() {
	cout << solution({ 1,1,1,1,1 }, 3);
}


/*
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int size = 1 << numbers.size();

	for(int i = 1 ; i < size ; i++){  // (00001 ~ 11111)
		int temp = 0;
		for(int j = 0 ; j < numbers.size() ; j++)
		{
			if(i &(1 << j)){ // 핵심 부분
				temp -= numbers[j]; // (numbers[0] ~ numbers[4])
			}
			else temp += numbers[j];
		}
		if(temp == target) answer++;
	}
	return answer;
}
*/