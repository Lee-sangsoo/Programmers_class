/*
작성자 : 이상수
일시 : 2021.04.23
제목 : 강한 결합 요소 (Strongly Connected Component)
풀이 : SCC란 그래프 안에서 '강하게 결합된 정점 집합'을 의미한다.
       서로 긴밀하게 연결되어 있다고 하여 강한 결합 요소라고 한다.

	   SCC는 '같은 SCC에 속하는 두 정점은 서로 도달이 가능하다'
	    - 사이클이 발생하는 경우 무조건 SCC에 해당한다.
		- 무향 그래프라면 그 그래프 전체는 무조건 SCC이다.

		SCC 추출 알고리즘
		1. 코사라주 알고리즘 (Kosaraju's Algorithm)
		2. 타잔 알고리즘 (Tarjan's Algorithm)

		코사라주가 타잔보다 쉽지만 타잔 알고리즘이 적용하기 더 쉽다는 점에서
		타잔 알고리즘을 공부하도록 한다.

		타잔 알고리즘
		- 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘

		(일종의 사이클의 개수와 사이클 경로를 찾는 과정이라고 볼 수 있다?)
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10000

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX]; // 실질적인 인접 노드를 담는 벡터
vector<vector<int>> SCC; // SCC를 담는 벡터
stack<int> s;

// DFS는 총 정점의 갯수만큼 실행됩니다.
int dfs(int x) {
	d[x] = ++id; // 노드마다 고유한 번호 할당
	s.push(x); // 스택에 자기 자신을 삽입합니다.

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		// 방문하지 않은 이웃
		if (d[y] == 0) parent = min(parent, dfs(y));
		// 처리 중인 이웃
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main() {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}
	cout << "SCC의 갯수 : " << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		cout << i + 1 << "번 째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << '\n';
	}
}