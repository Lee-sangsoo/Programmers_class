/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.05
���� : �޴� ������
Ǯ�� : �������� �־����� �迭�� ũ�Ⱑ �۾Ƽ� ���Ʈ������ ���� Ǯ �� �ִ�.
       �켱, ������ Ǯ�� ���� Ǯ�̸� �˻��ؼ� Ȯ�� �Ŀ� �м��ߴ�.
	   ��ŷ������ Ǯ�̸� ���� �˰ԵǾ���.

	   1. ��Ʈ����ũ�� ���� ���Ʈ���� ���� ���ϱ�
	   2. map ��ȸ�ÿ� ����ϴ� ���, map �迭 ���
	   (�� �ΰ����� ���ؼ��� �޸��忡 ������ �ξ���.)

	   �켱 �� �մԺ��� ��Ų ��ǰ �޴����� �������� �����Ѵ�.
	   �ش� ���� ������ map�� ���� �󸶳� ���׳� Ȯ���Ѵ�.

	   �� �� map�� ��ȸ�ϸ� ������ �����ϴ� ������� ã�� ������ ��ģ��.

	   ������ ���� ������ ����� ��� �غ��� ���̴�.
	   ���� ó���� ������ ��� ������ ���ϳ�...? ��� �ǹ��� �����̿���.

	   ��� ������ ���ϴ� ����� ���������� ������, ��Ʈ����ũ�� ����ϴ� ����� ����
	   �����ϰ� ª��. (�˾Ƶ���)

	   ���� ��ü�� 2������ ������ Ǯ�̸� �˰��� ���� ���� ��������.

	   ���� �� ���� �ִ�...
*/
#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> freq[11];
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	// ���� ���ϱ�
	for (auto order : orders) {
		sort(order.begin(), order.end());
		for (int i = 1; i < (1 << order.size()); i++) { // ABC -> 001 ~ 111 ����
			string menu;

			for (int j = 0; j < order.size(); j++) {
				if (i & (1 << j)) // i = 1 = 001 -> ABC �� 001 �̶�� -> A (�ݴ�� ����)
					menu += order[j];
			}

			freq[menu.size()][menu]++; // [���� ������ ����][����] ���� ����
		}
	}
	// ���� ã��
	for (auto i : course) { // i = 2, 3, 4
		int mxfreq = 0;
		for (auto p : freq[i]) // freq[2] => AC, AB, CD, ... // freq[3] => ABC, ABD, BCD, ...
			mxfreq = max(mxfreq, p.second); // p.second = ��Ų Ƚ��
		if (mxfreq < 2) continue; // ���� ���ǿ��� "�ּ� 2�� �̻��� �մ����κ��� �ֹ��� ���ո�" �����ϹǷ�
		for (auto p : freq[i]) { // 2�� �̻��� ���״ٸ� �ٽ� �ѹ� �ݺ����� ���鼭 �ڽ��丮�� answer�� ��´�.
			if (p.second == mxfreq) answer.push_back(p.first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	string k = "ABCDE";
	string s = "";
	for (int i = 0; i < k.size(); i++)
		if (3 & (1 << i))
			s += k[i];
	cout << s << '\n';

	map<string, int> tmp;
	tmp["A"] = 1;
	tmp["B"] = 2;
	for (auto i : tmp)
		cout << i.first << '\n';
}