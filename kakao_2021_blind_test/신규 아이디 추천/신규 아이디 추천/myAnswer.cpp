/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.08
���� : �ű� ���̵� ��õ
Ǯ�� : 1�� ������ ���� ������ ���� �����̴�.
       ������ Ǯ�鼭 ���ڿ��� ���õ� ���̺귯�� �Լ����� �ȴٸ� ���� ª�� �ڵ�� Ǯ�̰� �����ϴ�.
	   ��ü ������ Ǯ�̷� Ǯ�� �Ǿ���. (solution�� ��� ������ �ʹ� ���� ����� ���Ƽ�)

	   ������ Ǯ�̴� ��Ű�´�θ� �����ϸ� �Ǵ� �������� ũ�� ����� �ʰ� Ǯ �� �־���.

	   otherAnswer.cpp �� �ٸ� ����� ���ڿ� ���̺귯�� �Լ� ��� Ǯ�̰� �ִ�. 
	   �װ� Ȯ���ؼ� ��������. (�����ϴ�)
*/
#include <iostream>
#include <string>

using namespace std;

string first_step(string id) {
	string low = id;
	for (int i = 0; i < low.length(); i++) {
		low[i] = tolower(low[i]);
	}
	return low;
}

string second_step(string id) {
	string chk = "";
	for (int i = 0; i < id.length(); i++) {
		if (isdigit(id[i]) || islower(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.')
			chk += id[i];
	}
	return chk;
}

string third_step(string id) {
	string chk = "";
	bool checkPoint = false;
	for (int i = 0; i < id.length(); i++) {
		if (id[i] == '.') {
			if (!checkPoint) {
				chk += id[i];
				checkPoint = true;
			}
		}
		else {
			checkPoint = false;
			chk += id[i];
		}
	}
	return chk;
}

string fourth_step(string id) {
	string chk = "";
	if (id[0] != '.') chk += id[0];
	for (int i = 1; i < id.length() - 1; i++) {
		chk += id[i];
	}
	if (id[id.length() - 1] != '.') chk += id[id.length() - 1];
	return chk;
}

string fifth_step(string id) {
	if (id == "") return "a";
	else return id;
}

string sixth_step(string id) {
	string chk = "";
	if (id.length() < 16) return id;
	for (int i = 0; i < 14; i++)
		chk += id[i];
	if (id[14] != '.') chk += id[14];
	return chk;
}

string seventh_step(string id) {
	string chk = id;
	if (id.length() > 2) return id;
	while (chk.length() < 3) {
		chk += id[id.length() - 1];
	}
	return chk;
}

string solution(string new_id) {
	string answer = "";
	answer = first_step(new_id);
	answer = second_step(answer);
	answer = third_step(answer);
	answer = fourth_step(answer);
	answer = fifth_step(answer);
	answer = sixth_step(answer);
	answer = seventh_step(answer);
	return answer;
}

int main() {
	cout << solution("...!@BaT#*..y.abcdefghijklm");
}