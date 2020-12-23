#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	for (int i = 0; i < number.length(); i++) {
		while (!answer.empty() && answer.back() < number[i] && k > 0) {
			answer.pop_back();
			k--;
		}
		if (k == 0) {
			answer += number.substr(i, number.length() - i);
			break;
		}
		answer.push_back(number[i]);
	}

	return answer.substr(0, answer.length() - k);
}

// string ���� �񱳿��� ���ڿ��� ���̰� �ٸ� ��� ��� �񱳰� Ȯ������ ���� �� �ִ�.
// �� Ǯ�̴� ū���� ��� ���̴� ���

// ������ Ǯ�̴� �������� �ϳ��� ���� ������ ���

// �켱 ���� ó���� ������ �ϳ��� ��´�.
// ��� �� ���� ���� ���� Ȯ���Ͽ� �������� �� ũ�ٸ� �̹� ����� �ִ� ���� ������.
// �ݺ��Ѵ�.
// ��� ������ ������ k�� 0�� �Ǹ� ���� ������ ���� ���� ������ ��� ��´�.
//  �� �̰� �Ǵ� ������ �տ������� ū ���ڸ� ���� ���� ������ ��� ũ�� �Ǳ� ����
// �׸��� ���� ������ ���� ���̴� ����-k �̹Ƿ� �̸� substr�� �߶� �ѱ��.

// �� ����� O(n^2) ������ ����� O(n) �̰� �� ���� (���� �����ϴ�)