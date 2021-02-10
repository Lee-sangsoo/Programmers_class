/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.10
���� : ���� ����
Ǯ�� : ó�� �õ��� �� ��, ���� ����� �ð� ���⵵�� ���ϴ°� ������ �����ߴ�.
       ������, �� �ڿ� ��� ó������ ���� ����ϴٰ� Ǯ�̸� ���� ã�ƺ��Ҵ�.
	    (�޸��忡 �ڼ��� ����)
	   
	   ���� ��α��� Ǯ�̵鿡�� �� ������ "��������"�� ����ϸ� ���� ���� �ð��� 
	   Ǯ���� ������� �Ѵ�.
	   ������, �� ������ �������͸� �𸣰ų� ��Ȯ�� ���� ���Ѵٸ� Ǯ�� �ſ� ��ٷο� 
	   ������� �Ѵ�.

	   �׷��� �� ������ Ǫ�� �ٸ� ������� Prefix Sum �� �Ұ��� �ִ� Ǯ�̸� �����ߴ�.
	   (��ŷ����) (�ٵ� īī�� ��ũ ���� Ǯ�� �ۿ��� Prefix Sum���� Ǯ�̰� �ö���ִ�)
	   ���� ���� ����� ����ϴ�. �� �ð��븦 �ʷ� ȯ���Ͽ�
	   �ʸ� �迭�� �ε����� ����ϴ� ����̴�.

	   �� �������� �� 3���� ó���� Ǯ�̰� �ʿ��ϴ�.
	   1. �� �ð����� �ʷ� �ٲٴ� ����
	   2. logs�� ���� �ð����� �� �ð������� ���� ��û�ڼ��� +1 ���ִ°�
	   3. ���� ���� ��û�ڰ� �����ϴ� �ð��븦 ���ϴ� ����

	   �� 3���� �߿��� 1���� ������ �ذ� ����������,
	   2���� 3���� ��� ������ ������ �־�� �Ѵ�.
	   (�ּ��� �޸��忡 Ǯ��)

	   ���� ����� �������� �������� Ǯ�̵� �˰�� �־�� �Ұ� ����.
	   (���� ���ؼ� �������� Ǯ�� �ʿ�)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long viewer[360001];

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";

	if (play_time == adv_time) return "00:00:00";

	int total_time = 0; // �� ������ ����
	total_time += (stoi(play_time.substr(0, 2)) * 3600);
	total_time += (stoi(play_time.substr(3, 5)) * 60);
	total_time += stoi(play_time.substr(6, 8));

	int total_adv_time = 0; // �� ������ ����
	total_adv_time += (stoi(adv_time.substr(0, 2)) * 3600);
	total_adv_time += (stoi(adv_time.substr(3, 5)) * 60);
	total_adv_time += stoi(adv_time.substr(6, 8));

	for (auto lg : logs) {
		int start = 0; // �� log���� ���� �ð�
		int end = 0; // �� log���� �� �ð�

		start += (stoi(lg.substr(0, 2)) * 3600);
		start += (stoi(lg.substr(3, 5)) * 60);
		start += stoi(lg.substr(6, 8));

		end += (stoi(lg.substr(9, 11)) * 3600);
		end += (stoi(lg.substr(12, 14)) * 60);
		end += stoi(lg.substr(15, 17));

		// �̷��� ó���ϸ� �ð��ʰ��� ����
		// �ִ� 36�� �����̿��� �翬�ϴ�.
		/*
		for (int i = start; i < end; i++)
			viewer[i]++;
		*/
		viewer[start]++;
		viewer[end]--; // �� �κ��� 2���� �ش��ϸ� ���� ��û�� ���� ���ϴ� ����̴�.
	} 
	/*
		2���� ���ؼ�...
		�����ϰ� �������ڸ�, ���� �ð��� �迭 ���� + 1 ���ְ� �� �ð��� �迭 ���� -1 ���ִµ�,
		�� ������ �ǹ̴� "�ش� �ð��뿡 �þ ��û�� ��" �̴�.

		�ٽ� ���� 
		0�� �κ��� �ش� �ð��뿡 ��û�ڰ� �þ�� �ʰ� �� �ð��뿡�� �����ȴ�.
		��� ���̰�
		����� �κ��� �ش� �ð��뿡 ��û�ڰ� �ش� �� ��ŭ �þ�ٴ� �ǹ��̸�
		������ �κ��� �ش� �ð��뿡 ��û�ڰ� �ش� �� ��ŭ �پ����ٴ� �ǹ��̴�.

		�� �κ��� ó�� �� ���� �Ʒ� �ݺ����� ���� �� �ð��뺰 ���� ��û�� ���� ���� �� �ִ�.
	*/

	for (int i = 1; i <= total_time; i++) viewer[i] += viewer[i - 1]; // ���� ��û�� �� ���ϱ�

	long long now_time = 0;
	long long sum_time = 0;
	for (int i = 0; i < total_adv_time; i++)
		sum_time += viewer[i];

	long long max = sum_time;

	for (int i = 1; i <= (total_time - total_adv_time); i++) { // 3���� �ش��Ѵ�.
		sum_time -= viewer[i - 1];
		sum_time += viewer[i + total_adv_time - 1];
		if (max < sum_time) {
			now_time = i;
			max = sum_time;
		}
	}

	/*
		3���� ���ؼ�...
		�����ϰ� �������ڸ� �� �ð��� ���� ���� �ð���ŭ ��� �����Ͽ� ó������ �ʰ�
		���� �ܰ�� �Ѿ �� ���� �ܰ��� ó���� ���� ���ο� ���� �������� �־� ���ϴ� ����̴�.
		���� ��� ó�� 0 ~ 10 �� �ôٸ� 
		���� �ܰ迡���� 1 ~ 11�� ���ƾ� �ϴµ� �� �� 1 ~ 11�� �ٽ� ������ �ʰ�
		1 ~ 10 ������ ���� ������ �ֱ� ������
		0�� ���ְ� 11�� �����شٴ� ���̴�.
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