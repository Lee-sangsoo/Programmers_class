/*
�ۼ��� : �̻��
�Ͻ� : 2020.12.14
���� : �������� ���� ����
Ǯ�� : �ؽ� �� ����Ͽ� ó��
���ѻ��� : ������ ������ ���� 1�� �̻� 100,000�� ����
	       ���������� ���� �� �ִ�.
*/

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> runner;

	for (int i = 0; i < participant.size(); i++) {
		runner[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++) {
		runner[completion[i]]--;
	}

	for (int i = 0; i < participant.size(); i++) {
		if (runner[participant[i]] != 0) {
			return participant[i];
		}
	}

	return answer;
}

int main() {

}