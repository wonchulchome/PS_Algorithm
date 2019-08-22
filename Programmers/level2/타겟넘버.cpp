#include <string>
#include <vector>

#include <iostream>

using namespace std;
int cnt = 0;
void dfs(vector<int> a, int b, int c, int d);

int solution(vector<int> numbers, int target) {
	int answer = 0;

	dfs(numbers, target, 0, 0);

	answer = cnt;

	return answer;
}

void dfs(vector<int> numbers, int target, int ans, int x) {
	if (numbers.size() == x && ans == target) {
		cnt++;
		cout << "no" << endl;
		return;
	}
	else if (numbers.size() == x && ans != target) {
		return;
	}
	dfs(numbers, target, ans + numbers[x], x + 1);
	dfs(numbers, target, ans - numbers[x], x + 1);
}

int main() {
	vector<int> numbers = { 1,1,1,1,1 };
	cout << solution(numbers, 3) << endl;
	return 0;
}
