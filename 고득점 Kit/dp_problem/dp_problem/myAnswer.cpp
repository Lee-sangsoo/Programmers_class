/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.13
���� : N���� ǥ��
Ǯ�� : N���� �ݺ��Ͽ� Ư�� ���� ����ٴ� ���� 
	   � �� n�� �ݺ��ϸ� ������ ������
	   n�� 1�� = n
	   n�� 2�� = nn, [1�� (+, -, *, /) 1��] �� ����
	   ��, n�� N�� �ݺ��Ѵٴ� ���� = n~N, [1 N-1]
									      [2 N-2]
										  [3 N-3]
										    ...
										  [N-1 1] �� ����
	   �̸� �߽����� �Ϲ�ȭ�� �ϸ� �ȴ�.
���ѻ��� : N�� 1 �̻� 9 ����
           number�� 1 �̻� 32,000 ����
		   ��ȣ�� ��Ģ���길 �����ϸ�, ������ ���꿡�� �������� �����Ѵ�
		   �ּڰ��� 8���� ũ�� -1�� return�Ѵ�.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
	int answer = 0;
	vector<set<int>> arr;
	arr.push_back({ 0 }); // 0��° �ε��� (��� X)
	arr.push_back({ N }); // 1��° �ε��� (��� O)

	if (N == number) return 1;  // ���� ���� �־��ִ� N�� �����̶�� 1�� �ݺ��� ���̹Ƿ� 1�� return


	for (int n = 2; n < 9; n++) {
		set<int> tmp; // ��ø�Ǵ� ���� ���� ���� set �ڷᱸ�� ���
		string st = "";
		for (int i = 0; i < n; i++)
			st += to_string(N); // 55 555 5555 .... ���� set�� ����

		if (stoi(st) == number) return n; // �ش� ���� �����̶�� return
		

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
						tmp.insert(a / b); // ������ ����
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