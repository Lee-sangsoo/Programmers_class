/*
�Ͻ� : 2020.12.30
�ۼ� : �̻��
���� : ���α׷��ӽ� - �� �ʰ� (�׸���)
���� ���� : n���� �ſ� ������ �־��� ��, ���� ���� ���� �Ͱ� �������� ���� ����(1, 2��) ������
		    1�� + 2�� * 2 �Ͽ� ���ο� �ʱ⸦ �����, ��� n���� ���� �־����� �ſ� ���� k����
			Ŀ���� ���� �� ��ȸ�� ������ �� �ΰ��� ã�ƶ�
���ѻ��� : n�� ���̴� 1 �̻� 1,000,000 ����
		   k�� 0 �̻� 1,000,000,000 ����
		   n�� ���Ҵ� ���� 0 �̻� 1,000,000 ����
		   �Ұ����� ��� -1�� return
*/
#include <string>
#include <vector>
#include <queue> // heap ������ ���� priority_queue�� ����ϱ� ���� ����
				 // max heap�� min heap�� ������ �� �ִ�.

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;
			// �ڷ���, ��뱸��, �� ������
			// ���� less<int> ��� �������� �Ʒ��� ������ "Max heap" �̴�.
			// ���� greater<int> ��� ū ���� �Ʒ��� ������ "Min heap" �̴�.
	for (auto i : scoville)
		q.push(i);
	while (q.size() > 0) {
		if (q.top() >= K) {
			return answer;
		}
		int f = q.top();
		q.pop();
		if (q.empty()) break;
		int s = q.top();
		q.pop();
		q.push(f + s * 2);
		answer++;
	}
	return -1;
}

// heap�� ���� �����ϴ� �����
// �迭�� �̿��Ͽ� �����Ѵ�.
// ���� ��� �ε��� = current
// �θ� ��� �ε��� = current / 2
// �ڽ� ��� �ε��� => �� = current * 2, �� = current * 2 + 1

// ����
/*
void push(int data){
	heap[++current] = data;

	int child = current;
	int parent = child / 2;
	while(child > 1 && heap[parent] < heap[child]){ // �� ����� max heap
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child/2;
	}
}
*/

// ����
/*
int pop(){
	int result = heap[1]; // ������ ���� ��Ʈ����� ��

	swap(&heap[1], &heap[current]); // ��Ʈ�� ������ ����� ���� �ٲ۴�
	current--; // ��Ʈ�� ���� ���� ���̱⿡ current ���� ������.

	int parent = 1;
	int child = parent * 2;
	if(child + 1 <= current){
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	} // �ڽ� ���� �������� 2���� �ֱ� ������ �� ���߿��� �� ū ���� �����Ѵ�.

	while(child <= current && heap[parent] < heap[child]){ // �� �ڷ� �ڽ� ��� ��� Ȯ���Ͽ� �� ��ü
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = child * 2;
		if(child + 1 <= current){
			child = (heap[child] > heap[child + 1])?child : child + 1;
		}
	}

	return result;
}
*/