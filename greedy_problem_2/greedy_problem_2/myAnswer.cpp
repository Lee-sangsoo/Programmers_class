/*
�ۼ��� : �̻��
�Ͻ� : 2020.12.23
���� : ū �� �����
Ǯ�� : Ž����� ���� �ٽ� �����غ��� Ǯ�� ���� �����ϰų� ����� �ڷᱸ���� ����.
	   �� n���� ���� �ؾ� �Ѵٰ� �� ��, �ٽ� ���ϸ� �� "������ ���� - n"(=m) ���� ���� �Ͱ� ����
	   �׷��ٸ�, �� ������ŭ ���� ���ȿ� �ּ��� ������ �ִ��� ũ�⸦ ���� ���� ���� ����.
	   ��, ó�� �� �� �ִ� ���ڴ� ��ü ������ �ε��� 0���� k���� �̴�. �� �߿��� ���� ū ���� ���� �ȴ�.
	   �� ������ ���� ������ ������ �ٷ� ���� �ε��� ���� k+1����
	   �� ������ �ݺ��ϸ� �ִ� ũ���� ���ڸ� ������ �� �ִ�.
���ѻ��� : number�� 1�ڸ� �̻�, 1,000,000�ڸ� ������ ���� (string)
		   k�� 1 �̻� number�� �ڸ��� �̸��� �ڿ���
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int lop = number.length() - k; // �� �ݺ� Ƚ��
	int start = 0; // ������ 0����
	while (lop--) {
		int end = number.length() - lop; // �ᱹ�� k, k+1, k+2, ... �� �ȴ�.
		char maxs = '0';
		for (int i = start; i < end; i++) { // ������ ���� ���� ���� ���� ū ���� ã�´�.
			if (maxs < number[i]) {
				maxs = number[i];
				start = i + 1;
			}
		}
		answer += maxs;
	}

	return answer;
}

int main() {
	cout << solution("4177252841", 4);
}