/*
작성자 : 이상수
일시 : 2021.01.20
제목 : 주식가격
풀이 : 스택을 사용하여 index를 조작해야 하는데, 나는 이중 반복문으로 풀었다...
       다른 사람의 풀이를 확인한 결과 우선 가격이 떨어지는 부분만 캐치하여
	   스택에서 빼서 answer에 값을 넣어준 다음
	   나머지는 그 다음의 반복문을 통해 값을 계산해준다.

	   요점은 stack에 넣는것이 prices의 값이 아니라 해당 값의 인덱스라는 점

	   문제에 시간 제한이 없는것인지 O(n!) 로 풀어도 풀린다.

	   하지만, 스택을 사용하여 푸는 방식을 알아두자.
제한사항 : prices의 각 가격은 1 이상 10,000 이하인 자연수입니다.
           prices의 길이는 2 이상 100,000 이하입니다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) {
		int cnt = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			cnt++;
			if (prices[i] > prices[j]) break;
		}
		answer.push_back(cnt);
	}

	return answer;
}

int main() {
	vector<int> tmp = solution({ 1,2,3,2,3 });
	for (auto i : tmp)
		cout << i << ' ';
}



/*
다른 사람 풀이

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size();

	for (int i = 0; i<size; i++)
	{
		// 스텍이 차있으면서 가격이 떨어지기 시작하면
		while (!s.empty() && prices[s.top()] > prices[i])
		{
			answer[s.top()] = i - s.top();
			s.pop();
		}

		// 가격이 올라갈때동안 스텍에 넣음
		s.push(i);
	}

	// 스텍에 남은것들을 계산해줌
	while (!s.empty())
	{
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}

	return answer;
}
*/