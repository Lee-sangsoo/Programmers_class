/*
�Ͻ� : 2020.12.21
�ۼ� : �̻��
���� : ���α׷��ӽ� - ���� ū �� (����)
���� ���� : 0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� ã�ƶ�
���ѻ��� : numbers�� ���̴� 1�̻� 100,000 ����
		   numbers�� ���Ҵ� 0�̻� 1,000����
		   ������ string���� �ٲپ� return�Ѵ�.
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool check(int a, int b) {
	string c, d;
	c = to_string(a) + to_string(b);
	d = to_string(b) + to_string(a);

	return c > d; // ������ �� ��, ���� 3 �� 30�� �Դٰ� �������� ��
				  // �� ���� �̾� �ٿ� �񱳸� �غ��� �� ū ���� ������ ������ �ϸ� �ȴ�.
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), check);
	for (auto i : numbers) {
		answer += to_string(i);
	}
	if (answer[0] == '0') return "0";
	return answer;
}

int main() {
	cout << solution({ 0,0,0,0 });
}