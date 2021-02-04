/*
작성자 : 이상수
일시 : 2021.02.04
제목 : 카카오프렌즈 컬러링북
풀이 : BFS나 DFS를 통해 2차원 배열을 순회하며 연결된 값이 있는지 확인하며 최대값을 구하면 된다.

	   주의해야 하는 점으로는
	   1. 같은 색상을 골라야 하기 때문에 0이 아닌것을 고르는게 아닌
	   새로운 곳의 값과 스택에 있는 곳의 값이 같을 때만 값을 추가한다.

	   2. 0이 아닌 값을 순회하고자 할 때 새로운 값이 스택에 들어간다는 것은
	   갔다온적이 없는곳을 들어간다는 뜻이기 때문에 새로운 영역이다.

	   이를 주의하며 DFS나 BFS를 이용하면 간단하게 풀이 가능하다

	   근데 문제 테스트 케이스가 하나다.... 뭐지....
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	int paper[101][101] = { 0, };
	bool chk[101][101] = { 0, };
	int dist_x[4] = { 0,1,0,-1 };
	int dist_y[4] = { 1,0,-1,0 };

	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			paper[i][j] = picture[i][j];
		}
	}

	stack<pair<int, int>> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] != 0 && !chk[i][j]) {
				number_of_area++;
				s.push(make_pair(i, j));
				chk[i][j] = true;
				int cnt = 1;
				while (!s.empty()) {
					int x = s.top().first;
					int y = s.top().second;
					s.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dist_x[k];
						int ny = y + dist_y[k];
						if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
							if (!chk[nx][ny] && paper[x][y] == paper[nx][ny]) {
								s.push(make_pair(nx, ny));
								chk[nx][ny] = true;
								cnt++;
							}
						}
					}

				}
				max_size_of_one_area = max_size_of_one_area < cnt ? cnt : max_size_of_one_area;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	//vector<int> tmp = solution(6, 4, { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} });
	vector<int> tmp = solution(1, 1, { {1} });
	cout << tmp[0] << ' ' << tmp[1];
}