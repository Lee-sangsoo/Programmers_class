/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.26
���� : ���̽�ƽ
Ǯ�� : ��, �Ʒ��� �����̴� ���� ���� �����ϴ�,
	   �׳� �ƽ�Ű �� �����ؼ� �ش� �� ���ְ� ���� �� �����ϸ� �ȴ�.
	   (�ٸ� Ǯ���� ��� map�� ������� �ʰ� �׳� �迭�� ��Į�ڸ��� ������ ���� �̰� �� ȿ�����̴�)

	   ��, ��� �����̴� �� �����ε� �켱 �����ڸ�
	   �� ������ �κ� �����ذ� ��ü �����ذ� ���� �ʴ´�.
	   �׸��� ������ �ƴ϶�� ������ ���...

	   �׸��� ������ ��ŭ Ž�彺���� �����ϸ� ���� ����� ���� �ٲܰ� �ִٸ�
	   �� �κк��� ���� ���� �Ǵ� ���ε�, �׷��� �ϸ� �ݷʰ� �����Ѵ�.

	   ������ �׷��� Ǯ� ������ ����Ѵ�...

	   �� Ǯ�̴� Ž��� ���� Ǯ������, �� Ǯ�̿� �ݷʰ� �����Ѵ�.

	   �ٸ� ����� Ǯ�� �� ��κ��� �߸��� Ǯ�̰� �־�����
	   �ùٸ� Ǯ�̰� �ϳ� �־ ������ �Դ�. (�Ʒ� �ּ�)
	   ������ �� �ڵ尡 ���� �������� ���ظ� ���� ���ϰڴ�....

	   ���������� ����Ѵٴµ� ���� ������...
���ѻ��� : name�� ���ĺ� �빮�ڷθ� �̷���� �ֽ��ϴ�.
	       name�� ���̴� 1 �̻� 20 �����Դϴ�.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string name) {
	int answer = 0;
	string s = "";
	map<char, int> arr;
	map<char, int> arr_r;

	for (int i = 0; i < 26; i++) {
		arr[char(65 + i)] = i;
		arr_r[char(90 - i)] = i + 1;
	}

	for (int i = 0; i < name.length(); i++)
		s += "A";

	int i = 0;
	while (s != name) {
		for (int j = 0; j < name.length() / 2 + 1; j++) {
			int n1 = i + j;
			int n2 = i - j;

			if (n1 > name.length() - 1)
				n1 = ((i + j) - name.length());

			if (n2 < 0)
				n2 = (name.length() + (i - j));

			if (s[n1] != name[n1]) {
				answer += j;
				i = n1;
				break;
			}
			else if (s[n2] != name[n2]) {
				answer += j;
				i = n2;
				break;
			}
		}

		answer += (arr[name[i]] > arr_r[name[i]] ? arr_r[name[i]] : arr[name[i]]);
		s[i] = name[i];
	}

	return answer;
}

int main() {
	cout << solution("ABABAAAAAAABA");
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
	int answer = 0;

	for (auto ch : name)
		answer += LUT[ch - 'A'];

	int len = name.length();
	int left_right = len - 1;


	// !-----------���⼭ ����
	for (int i = 0; i < len; ++i) {
		int next_i = i + 1;

		while (next_i < len && name[next_i] == 'A')
			next_i++;

		left_right = min(left_right, i + len - next_i + min(i, len - next_i));
		// ������� ���� �Ұ� ------------------------------!
	}

	answer += left_right;
	return answer;
}
*/