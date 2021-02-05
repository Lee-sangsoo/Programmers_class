/*
일시 : 2020.12.30
작성 : 이상수
문제 : 프로그래머스 - 더 맵게 (그리디)
문제 설명 : n개의 매움 정도가 주어질 때, 가장 맵지 않은 것과 다음으로 맵지 않은(1, 2등) 음식을
		    1등 + 2등 * 2 하여 새로운 맵기를 만들고, 모든 n개의 수가 주어지는 매움 정도 k보다
			커지는 경우는 총 몇회를 섞었을 때 인가를 찾아라
제한사항 : n의 길이는 1 이상 1,000,000 이하
		   k는 0 이상 1,000,000,000 이하
		   n의 원소는 각각 0 이상 1,000,000 이하
		   불가능한 경우 -1을 return
*/
#include <string>
#include <vector>
#include <queue> // heap 구현을 위한 priority_queue를 사용하기 위해 선언
				 // max heap과 min heap을 구현할 수 있다.

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> q;
			// 자료형, 사용구조, 비교 연산자
			// 만약 less<int> 라면 적은것을 아래로 보내는 "Max heap" 이다.
			// 만약 greater<int> 라면 큰 것을 아래로 보내는 "Min heap" 이다.
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

// heap을 직접 구현하는 방법은
// 배열을 이용하여 구현한다.
// 현재 노드 인덱스 = current
// 부모 노드 인덱스 = current / 2
// 자식 노드 인덱스 => 좌 = current * 2, 우 = current * 2 + 1

// 삽입
/*
void push(int data){
	heap[++current] = data;

	int child = current;
	int parent = child / 2;
	while(child > 1 && heap[parent] < heap[child]){ // 이 방식은 max heap
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child/2;
	}
}
*/

// 삭제
/*
int pop(){
	int result = heap[1]; // 삭제할 값은 루트노드의 값

	swap(&heap[1], &heap[current]); // 루트와 마지막 노드의 값을 바꾼다
	current--; // 루트는 쓰지 않을 것이기에 current 값을 내린다.

	int parent = 1;
	int child = parent * 2;
	if(child + 1 <= current){
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	} // 자식 노드는 양쪽으로 2개가 있기 때문에 두 값중에서 더 큰 값을 선정한다.

	while(child <= current && heap[parent] < heap[child]){ // 그 뒤로 자식 노드 모두 확인하여 값 교체
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