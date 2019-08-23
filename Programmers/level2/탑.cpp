#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	queue<int> q;
	q.push(0);//맨앞은 무조건 0이므로

	for (int i = 1; i < heights.size(); ++i) {
		for (int j = i-1; j >= 0; --j) {
			if (heights[i] < heights[j]) {
				q.push(j+1);
				break;
			}
			if (j == 0) {
				q.push(0);
			}
		}
	}

	int size = q.size();
	for (int i = 0; i < size; ++i) {
		answer.push_back(q.front());
		q.pop();
	}

	return answer;
}

int main() {
	vector<int> h1 = { 6,9,5,7,4 };
	vector<int> h2 = { 3,9,9,3,5,7,2 };
	vector<int> h3 = { 1,5,3,6,7,6,5 };

	for (auto a : solution(h1)) {
		cout << a << " ";
	}
	cout << endl;

	for (auto a : solution(h2)) {
		cout << a << " ";
	}
	cout << endl;

	for (auto a : solution(h3)) {
		cout << a << " ";
	}
	cout << endl;

	return 0;
}
