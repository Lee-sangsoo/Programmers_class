/*
작성자 : 이상수
일시 : 2021.01.13
제목 : N으로 표현
풀이 : N번을 반복하여 특정 수를 만든다는 것은 
	   어떤 수 n을 반복하면 나오는 수들은
	   n이 1번 = n
	   n이 2번 = nn, [1번 (+, -, *, /) 1번] 과 같다
	   즉, n이 N번 반복한다는 것은 = n~N, [1 N-1]
									      [2 N-2]
										  [3 N-3]
										    ...
										  [N-1 1] 과 같다
	   이를 중심으로 일반화를 하면 된다.
제한사항 : N은 1 이상 9 이하
           number는 1 이상 32,000 이하
		   괄호와 사칙연산만 가능하며, 나누기 연산에서 나머지는 무시한다
		   최솟값이 8보다 크면 -1을 return한다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
	int answer = 0;
	vector<set<int>> arr;
	arr.push_back({ 0 }); // 0번째 인덱스 (사용 X)
	arr.push_back({ N }); // 1번째 인덱스 (사용 O)

	if (N == number) return 1;  // 가장 먼저 넣어주는 N이 정답이라면 1번 반복한 것이므로 1을 return


	for (int n = 2; n < 9; n++) {
		set<int> tmp; // 중첩되는 값을 막기 위해 set 자료구조 사용
		string st = "";
		for (int i = 0; i < n; i++)
			st += to_string(N); // 55 555 5555 .... 만들어서 set에 삽입

		if (stoi(st) == number) return n; // 해당 값이 정답이라면 return
		

		tmp.insert(stoi(st));

		for (int i = 1; i < n; i++) {
			for (auto a : arr[i]) { 
				for (auto b : arr[n-i]) {  // i - j == 1 - n-1 
					if (a + b == number || a - b == number || a * b == number || (a != 0 && b != 0 && a / b == number))
						return n;

					tmp.insert(a + b);
					tmp.insert(a - b);
					tmp.insert(a * b);
					if(a != 0 && b != 0)
						tmp.insert(a / b); // 나누기 조심
				}
			}
		}

		arr.push_back(tmp);
	}
	
	return -1;
}

int main() {
	cout << solution(5, 5);
}