/*
작성자 : 이상수
일시 : 2021.01.29
제목 : 등굣길
풀이 : 동적 프로그래밍 문제 중에서 점화식을 도출하는 과정은 정말 간단했다.
       문제에서 아래와 오른쪽으로만 이동 가능하다고 말을 했기 때문에
	   이를 이용하여 풀면 된다.

	   고민했던 몇가지가 있는데
	   우선 가장 오래 동안 고민한, m과 n의 주어진 격자가 일반적으로 생각하는 [n][m] 이지만 반대로 주어진다는 것
	   이것 때문에 [n][m]으로 생각하고 풀다가 물 웅덩이의 위치가 [m][n]으로 주어지는 거 때문에 한번 실패했다.

	   그 다음으로 집에서 오른쪽으로만 가거나 아래로만 가는 경우는 해당 경로의 경우의 수가 모두 1인데
	   만약 그 중 물 웅덩이가 있다면 그 뒤로는 모두 가지 못하기 때문에 0이 된다. (break로 구현)

	   정답을 특정 수로 나눈 나머지를 return 하라고 한 것 

	   문제를 잘 읽었으면 한번에 통과 했을 고민들이다.

	   문제를 잘 읽자
제한사항 : m, n의 크기는 1 이상 100 이하
		   물에 잠긴 지역은 0개 이상 10개 이하
		   집과 학교는 물에 잠기지 않는다.
*/
#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];
bool chk[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	for (int i = 0; i < puddles.size(); i++) {
		chk[puddles[i][1] - 1][puddles[i][0] - 1] = 1;
	}

	bool use = false;
	for (int i = 0; i < n; i++) {
		if (chk[i][0]) break;
		arr[i][0] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (chk[0][i]) break;
		arr[0][i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (!chk[i][j])
				arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
		}
	}

	answer = arr[n - 1][m - 1];
	return answer;
}

int main() {
	cout << solution(4, 3, { {2,1} });
}