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

// string 간의 비교에서 문자열의 길이가 다를 경우 대소 비교가 확실하지 않을 수 있다.
// 내 풀이는 큰것을 골라 붙이는 방식

// 강의의 풀이는 작은것을 하나씩 때어 나가는 방식

// 우선 가장 처음의 수부터 하나씩 담는다.
// 담아 둔 값을 다음 값과 확인하여 다음값이 더 크다면 이미 담겨져 있는 값을 버린다.
// 반복한다.
// 모든 과정이 끝나고 k가 0이 되면 아직 비교하지 않은 남은 값들을 모두 담는다.
//  ㄴ 이게 되는 이유는 앞에서부터 큰 숫자를 골라야 남은 값들이 모두 크게 되기 때문
// 그리고 남은 값에서 최종 길이는 길이-k 이므로 이를 substr로 잘라서 넘긴다.

// 내 방식은 O(n^2) 강의의 방식은 O(n) 이게 더 좋다 (조금 복잡하다)