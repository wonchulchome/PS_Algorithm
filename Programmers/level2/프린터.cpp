#include <string>
#include <vector>
#include <queue>

#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int cnt = 0;

	queue<pair<int, int>> q;
	priority_queue<int> pq;

	for (int i = 0; i < priorities.size(); ++i) {
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	while (!q.empty()) {
		int idx = q.front().first;//위치
		int val = q.front().second;//우선순위
		q.pop();

		if (pq.top() == val) {//둘의 우선순위가 같다면
			pq.pop();//일단 꺼내고
			cnt++;//하나 카운트
			if (idx == location) {//위치가 맞다면
				answer = cnt;
				break;
			}
		} else {//우선순위 다르면(더 작다면)
			q.push(make_pair(idx, val));//맨뒤로 넣어줌
		}
	}

	return answer;
}

int main() {

	vector<int> v1 = { 2,1,3,2 };
	vector<int> v2 = { 1,1,9,1,1,1 };

	cout << solution(v1, 2) << endl;
	cout << solution(v2, 0) << endl;

	return 0;
}

/*
처음에 생각없이 말그대로 시뮬레이션으로 돌렸다.
큐 하나 만들어서 맨앞에서 비교하면서 뒤로 넣어주고 했는데 시간초과...
그래서, 우선순위큐를 하나 더 만들어서 맨 앞의 값과 비교해서 바로 뒤로 넣어주니 통과
***(가장 우선순위가 큰것을 매번 다시 검색하면서 시간초과가 난 것 같다)***
*/
