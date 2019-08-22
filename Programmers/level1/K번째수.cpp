#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int n = 0; n < commands.size(); ++n) {
		int i = commands[n][0] - 1;
		int j = commands[n][1];
		int k = commands[n][2];
		vector<int> subNumber;
		for (int idx = i; idx < j; ++idx) {
			subNumber.push_back(array[idx]);
		}
		sort(subNumber.begin(), subNumber.end());
		answer.push_back(subNumber[k - 1]);
	}

	return answer;
}
