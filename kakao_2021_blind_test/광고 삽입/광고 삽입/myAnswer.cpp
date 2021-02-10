/*
작성자 : 이상수
일시 : 2021.02.10
제목 : 광고 삽입
풀이 : 처음 시도를 할 때, 접근 방법과 시간 복잡도를 구하는것 까지는 가능했다.
       하지만, 그 뒤에 어떻게 처리할지 몰라서 고민하다가 풀이를 조금 찾아보았다.
	    (메모장에 자세히 정리)
	   
	   여러 블로그의 풀이들에서 이 문제는 "투포인터"를 사용하면 가장 빠른 시간에 
	   풀리는 문제라고 한다.
	   하지만, 이 문제는 투포인터를 모르거나 정확히 알지 못한다면 풀기 매우 까다로운 
	   문제라고 한다.

	   그래서 이 문제를 푸는 다른 방법으로 Prefix Sum 을 소개해 주는 풀이를 참조했다.
	   (바킹독님) (근데 카카오 테크 공식 풀이 글에는 Prefix Sum으로 풀이가 올라와있다)
	   대충 접근 방법은 비슷하다. 각 시간대를 초로 환산하여
	   초를 배열의 인덱스로 사용하는 방식이다.

	   이 문제에서 총 3가지 처리와 풀이가 필요하다.
	   1. 각 시간들을 초로 바꾸는 과정
	   2. logs의 시작 시간부터 끝 시간까지의 누적 시청자수를 +1 해주는것
	   3. 가장 많은 시청자가 존재하는 시간대를 정하는 과정

	   이 3가지 중에서 1번은 간단히 해결 가능하지만,
	   2번과 3번의 경우 조금의 지식이 있어야 한다.
	   (주석과 메모장에 풀이)

	   정말 어려운 문제였고 투포인터 풀이도 알고는 있어야 할것 같다.
	   (백준 통해서 투포인터 풀이 필요)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long viewer[360001];

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";

	if (play_time == adv_time) return "00:00:00";

	int total_time = 0; // 총 영상의 길이
	total_time += (stoi(play_time.substr(0, 2)) * 3600);
	total_time += (stoi(play_time.substr(3, 5)) * 60);
	total_time += stoi(play_time.substr(6, 8));

	int total_adv_time = 0; // 총 광고의 길이
	total_adv_time += (stoi(adv_time.substr(0, 2)) * 3600);
	total_adv_time += (stoi(adv_time.substr(3, 5)) * 60);
	total_adv_time += stoi(adv_time.substr(6, 8));

	for (auto lg : logs) {
		int start = 0; // 각 log들의 시작 시간
		int end = 0; // 각 log들의 끝 시간

		start += (stoi(lg.substr(0, 2)) * 3600);
		start += (stoi(lg.substr(3, 5)) * 60);
		start += stoi(lg.substr(6, 8));

		end += (stoi(lg.substr(9, 11)) * 3600);
		end += (stoi(lg.substr(12, 14)) * 60);
		end += stoi(lg.substr(15, 17));

		// 이렇게 처리하면 시간초과가 난다
		// 최대 36만 제곱이여서 당연하다.
		/*
		for (int i = start; i < end; i++)
			viewer[i]++;
		*/
		viewer[start]++;
		viewer[end]--; // 이 부분이 2번에 해당하며 누적 시청자 수를 구하는 방식이다.
	} 
	/*
		2번에 대해서...
		간단하게 설명하자면, 시작 시간의 배열 값을 + 1 해주고 끝 시간의 배열 값을 -1 해주는데,
		이 가감의 의미는 "해당 시간대에 늘어난 시청자 수" 이다.

		다시 말해 
		0인 부분은 해당 시간대에 시청자가 늘어나지 않고 전 시간대에서 유지된다.
		라는 뜻이고
		양수인 부분은 해당 시간대에 시청자가 해당 수 만큼 늘어났다는 의미이며
		음수인 부분은 해당 시간대에 시청자가 해당 수 만큼 줄어들었다는 의미이다.

		이 부분을 처리 한 다음 아래 반복문과 같이 각 시간대별 누적 시청자 수를 구할 수 있다.
	*/

	for (int i = 1; i <= total_time; i++) viewer[i] += viewer[i - 1]; // 누적 시청자 수 구하기

	long long now_time = 0;
	long long sum_time = 0;
	for (int i = 0; i < total_adv_time; i++)
		sum_time += viewer[i];

	long long max = sum_time;

	for (int i = 1; i <= (total_time - total_adv_time); i++) { // 3번에 해당한다.
		sum_time -= viewer[i - 1];
		sum_time += viewer[i + total_adv_time - 1];
		if (max < sum_time) {
			now_time = i;
			max = sum_time;
		}
	}

	/*
		3번에 대해서...
		간단하게 설명하자면 각 시간대 별로 광고 시간만큼 모두 가감하여 처리하지 않고
		다음 단계로 넘어갈 때 이전 단계의 처음을 빼고 새로운 곳의 마지막을 넣어 비교하는 방식이다.
		예를 들어 처음 0 ~ 10 을 봤다면 
		다음 단계에서는 1 ~ 11을 보아야 하는데 이 때 1 ~ 11을 다시 더하지 않고
		1 ~ 10 까지는 값을 가지고 있기 때문에
		0을 빼주고 11만 더해준다는 뜻이다.
	*/

	string h = "";
	string m = "";
	string s = "";
	h = to_string(now_time / 3600).length() > 1 ? to_string(now_time / 3600) : "0" + to_string(now_time / 3600);
	now_time = now_time % 3600;
	m = to_string(now_time / 60).length() > 1 ? to_string(now_time / 60) : "0" + to_string(now_time / 60);
	now_time = now_time % 60;
	s = to_string(now_time).length() > 1 ? to_string(now_time) : "0" + to_string(now_time);
	answer += (h + ":" + m + ":" + s);
	return answer;
}

int main() {
	cout << solution("99:59:59", "25:00:00",
		{ "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" });
}