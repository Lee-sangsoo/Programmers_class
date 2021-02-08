/*
다른 사람의 풀이 (라이브러리 함수 다수 이용)
	1. strchr("string", 문자) -> string 안에 문자가 있으면 실행된다.
	2. string.clear() -> 문자열 비우기
	3. string.begin(), string.back() -> 앞 뒤
	4. string.erase(위치) -> 위치의 문자 삭제
	5. string.pop_back() -> 문자열의 가장 뒤 문자 삭제
	6. string.substr(시작, 끝) -> 해당 범위의 문자로 잘라내기
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