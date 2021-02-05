/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.20
���� : �ֽİ���
Ǯ�� : ������ ����Ͽ� index�� �����ؾ� �ϴµ�, ���� ���� �ݺ������� Ǯ����...
       �ٸ� ����� Ǯ�̸� Ȯ���� ��� �켱 ������ �������� �κи� ĳġ�Ͽ�
	   ���ÿ��� ���� answer�� ���� �־��� ����
	   �������� �� ������ �ݺ����� ���� ���� ������ش�.

	   ������ stack�� �ִ°��� prices�� ���� �ƴ϶� �ش� ���� �ε������ ��

	   ������ �ð� ������ ���°����� O(n!) �� Ǯ� Ǯ����.

	   ������, ������ ����Ͽ� Ǫ�� ����� �˾Ƶ���.
���ѻ��� : prices�� �� ������ 1 �̻� 10,000 ������ �ڿ����Դϴ�.
           prices�� ���̴� 2 �̻� 100,000 �����Դϴ�.
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
�ٸ� ��� Ǯ��

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
		// ������ �������鼭 ������ �������� �����ϸ�
		while (!s.empty() && prices[s.top()] > prices[i])
		{
			answer[s.top()] = i - s.top();
			s.pop();
		}

		// ������ �ö󰥶����� ���ؿ� ����
		s.push(i);
	}

	// ���ؿ� �����͵��� �������
	while (!s.empty())
	{
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}

	return answer;
}
*/