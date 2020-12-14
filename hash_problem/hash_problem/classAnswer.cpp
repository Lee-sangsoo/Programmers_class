/*
�ۼ��� : �̻��
�Ͻ� : 2020.12.14
���� : �������� ���� ����
Ǯ�� : �ؽ� �� ����Ͽ� ó��
���ѻ��� : ������ ������ ���� 1�� �̻� 100,000�� ����
		   ���������� ���� �� �ִ�.
*/

// ���� ������ Ǯ��

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> runner;

	for (auto &i : participant) runner[i]++;

	for (auto &i : completion) runner[i]--;

	for (auto &i : runner) {
		if (i.second != 0) {
			return i.first;
		}
	}

	return answer;
}

int main() {

}