#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(int brown, int red) {
	vector<int> answer;

	int width = brown + red;
	for (int i = 3; i <= width / 3; ++i) {//최소 세로 길이가 3이상이여야 함
		if (width % i == 0) {
			if ((width / i - 2) * (i - 2) == red) {
				answer.push_back(width / i);
				answer.push_back(i);
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<int> ans1;
	vector<int> ans2;
	vector<int> ans3;

	ans1 = solution(10, 2);
	cout << ans1[0] << "," << ans1[1] << endl;

	ans2 = solution(8, 1);
	cout << ans2[0] << "," << ans2[1] << endl;

	ans3 = solution(24, 24);
	cout << ans3[0] << "," << ans3[1] << endl;
	return 0;
}
