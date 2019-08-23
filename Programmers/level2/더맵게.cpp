#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); ++i) {
		pq.push(scoville[i]);
	}
	int first = 0;
	int second = 0;
	while (!pq.empty()) {
		if (pq.top() >= K) {
			break;
		}
		first = pq.top();
		pq.pop();
		if (pq.empty()) {
			answer = -1;
			break;
		}
		second = pq.top();
		pq.pop();

		pq.push(first + second * 2);
		answer++;
	}

	return answer;
}

int main() {
	vector<int> sco = { 1,2,3,9,10,12 };
	int k = 7;

	cout << solution(sco, k) << endl;

	return 0;
}
