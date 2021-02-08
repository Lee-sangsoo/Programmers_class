/*
�ٸ� ����� Ǯ�� (���̺귯�� �Լ� �ټ� �̿�)
	1. strchr("string", ����) -> string �ȿ� ���ڰ� ������ ����ȴ�.
	2. string.clear() -> ���ڿ� ����
	3. string.begin(), string.back() -> �� ��
	4. string.erase(��ġ) -> ��ġ�� ���� ����
	5. string.pop_back() -> ���ڿ��� ���� �� ���� ����
	6. string.substr(����, ��) -> �ش� ������ ���ڷ� �߶󳻱�
*/
#include <iostream>
#include <string>
using namespace std;

string solution(string new_id) {
	for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

	string ret;
	for (char& ch : new_id) {
		if ('a' <= ch && ch <= 'z' ||
			'0' <= ch && ch <= '9' ||
			strchr("-_.", ch)) ret += ch;
	}

	new_id = ret;
	ret.clear();
	for (char& ch : new_id) {
		if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
		ret += ch;
	}

	if (ret.front() == '.') ret.erase(ret.begin());
	if (ret.back() == '.') ret.pop_back();

	if (ret.empty()) ret = "a";
	if (ret.size() >= 16) ret = ret.substr(0, 15);
	if (ret.back() == '.') ret.pop_back();
	while (ret.size() <= 2) ret += ret.back();

	return ret;
}