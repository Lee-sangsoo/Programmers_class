#include<iostream>
#include <string>
#include <vector>

using namespace std;

int count(long long v) {
	v = (v & 0x55555555) + ((v >> 1) & 0x55555555);
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
	v = (v & 0x0f0f0f0f) + ((v >> 4) & 0x0f0f0f0f);
	v = (v & 0x00ff00ff) + ((v >> 8) & 0x00ff00ff);
	v = (v & 0x0000ffff) + ((v >> 16) & 0x0000ffff);
	return v;
}

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); i++) {
		long long cur = numbers[i];
		for (long long j = cur + 1; ; j++) {
			long long now = (cur ^ j);
			long long cnt = count(now);

			if (cnt < 3) {
				answer.push_back(j);
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<long long> tmp = solution({ 2, 7, 98989898989898 });
	for (auto i : tmp)
		cout << i << ' ';
}