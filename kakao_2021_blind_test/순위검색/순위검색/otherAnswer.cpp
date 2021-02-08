#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

const string ALL = "-";
unordered_map<string, vector<int>> map;

void insert(string* key, int mask, int point) {
	string s = "";
	for (int i = 0; i < 4; i++) {
		s += (mask & (1 << i)) ? ALL : key[i];
		map[s].push_back(point);
	}
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	string key[4], tmp;
	int point;

	for (auto& inf : info) {
		istringstream iss(inf);
		iss >> key[0] >> key[1] >> key[2] >> key[3] >> point;
		for (int i = 0; i < 16; i++) insert(key, i, point); // 0000 ~ 1111
	}

	for (auto& m : map) sort(m.second.begin(), m.second.end());

	for (auto& que : query) {
		istringstream iss(que);
		iss >> key[0] >> tmp >> key[1] >> tmp >> key[2] >> tmp >> key[3] >>
			point;
		string s = key[0] + key[1] + key[2] + key[3];
		vector<int>& v = map[s];
		answer.push_back(v.end() - lower_bound(v.begin(), v.end(), point));
	}

	return answer;
}

/*
	1. istringstream -> istringstream iss(string)를 해주면
		iss에 string의 값이 space나 tap으로 파싱되어 들어간다.
		이 값들을 iss >> string >> string >> .... 하면
		iss의 파싱된 값들이 string에 들어가게된다.

		즉 info를 돌 때는 공백으로 구분되어 있기 때문에 5개를 해주면 되고
		query를 돌 때는 and가 포함되어 있기 때문에 and를 tmp에 넣어주는 모습이다.

	2. bitMask 사용
	3. lower_bound(begin(), end(), target)
	4. upper_bound(begin(), end(), target)
*/