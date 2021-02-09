/*
작성자 : 이상수
일시 : 2021.02.09
제목 : 합승 택시 요금
풀이 : 플로이드 알고리즘을 사용하면 되는 문제
       얼떨결에 카카오 테크에서 공식 풀이를 봐버렸다.
	   처음 생각할 때에는 어려웠을것 같으나, 풀이를 본 때문인지 정말 간단했다.

	   플로이드 알고리즘을 통해 각 정점까지의 최소 거리를 구한 다음
	   1. 시작 정점(S)에서 합승을 마칠 정점(i)까지의 비용
	   2. 합승이 끝난 정점(i)에서 A의 집이 있는 정점(a) 까지의 비용
	   3. 합승이 끝난 정점에서 B의 집이 있는 정점(b) 까지의 비용
	   모든 정점을 순회하며 1, 2, 3을 더한 값 중 가장 작은 값을 선택하도록 한다.

	   이게 정답이다.

	   다만, 플로이드 알고리즘을 위해 처리한 987654321의 경우 
	   합승을 마친 정점이 자신의 집인 경우도 있기 때문에 
	   플로이드 알고리즘을 마친 다음에 [i][i] = 자기 자신으로의 비용은 0으로 처리해주어야 한다.
	   (아래에 있는 코드는 0으로의 처리를 하지 않아서 조건문을 마구 넣은것이다)

	   그리고 기초값을 너무 크게 잡아서 continue문을 사용하지 않으면 오버플로우가 생겼다.
	   answer를 long long으로 주거나 continue를 주면 해결되었다
	   (길이 없다는 뜻이므로 continue로 처리하는게 맞을것 같다)
*/
#include <iostream>
#include <vector>

using namespace std;

int dist[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 987654321;
		}
	}

	for (int i = 0; i < fares.size(); i++) {
		for (int j = 0; j < fares[i].size(); j++) {
			dist[fares[i][0]][fares[i][1]] = fares[i][2];
			dist[fares[i][1]][fares[i][0]] = fares[i][2];
		}
	}

	for (int n1 = 1; n1 <= n; n1++) { // 거쳐가는 정점
		for (int n2 = 1; n2 <= n; n2++) { // 시작 정점
			for (int n3 = 1; n3 <= n; n3++) { // 도착 정점
				if (dist[n2][n3] > dist[n2][n1] + dist[n1][n3])
					dist[n2][n3] = dist[n2][n1] + dist[n1][n3];
			}
		}
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0; // 모든 자기 자신으로의 비용 0

	answer = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++) {
		// continue 부분을 처리하기 싫다면 값이 너무 커지기 때문에 long long으로 바꿔주면 된다.
		if (dist[s][i] == 987654321 || dist[i][a] == 987654321 || dist[i][b] == 987654321) continue;
		if (answer > dist[s][i] + dist[i][a] + dist[i][b])
			answer = dist[s][i] + dist[i][a] + dist[i][b];
		
	}

	return answer;
}

int main() {
	
}

/*
	// 처음 접근한 방법 i -> i로 가는 부분을 0으로 처리하지 않아서 모든 조건을 확인했다.
	// 위 풀이에서 그냥 dist[i][i]를 0으로 초기화 하면 되는 문제였다.
	answer = dist[s][a] + dist[s][b];
	for (int i = 1; i <= n; i++) {
		if (dist[s][i] == 987654321 || dist[i][a] == 987654321 || dist[i][b] == 987654321) continue;

		if (i == a || i == b) {
			if (i == a && i == b) {
				if (answer > dist[s][i])
					answer = dist[s][i];
			}
			else if (i == a) {
				if (answer > dist[s][i] + dist[i][b])
					answer = dist[s][i] + dist[i][b];
			}
			else if (i == b) {
				if (answer > dist[s][i] + dist[i][a])
					answer = dist[s][i] + dist[i][a];
			}
		}
		else {
			if (answer > dist[s][i] + dist[i][a] + dist[i][b])
				answer = dist[s][i] + dist[i][a] + dist[i][b];
		}

	}
*/