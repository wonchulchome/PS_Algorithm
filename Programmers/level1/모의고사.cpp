#include <string>
#include <vector>

using namespace std;

int supoja1[5] = { 1,2,3,4,5 };
int supoja2[8] = { 2,1,2,3,2,4,2,5 };
int supoja3[10] = { 3,3,1,1,2,2,4,4,5,5 };

int max(int a, int b) {
	return a > b ? a : b;
}

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == supoja1[i % 5]) cnt1++;
		if (answers[i] == supoja2[i % 8]) cnt2++;
		if (answers[i] == supoja3[i % 10]) cnt3++;
	}
	
	int maxCount = max(max(cnt1, cnt2), cnt3);

	if (maxCount == cnt1) answer.push_back(1);
	if (maxCount == cnt2) answer.push_back(2);
	if (maxCount == cnt3) answer.push_back(3);

	return answer;
}
