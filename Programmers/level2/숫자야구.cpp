#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	for (int i = 123; i < 987; i++) {
		int x = i % 10;//1자리
		int y = (i / 10) % 10;//10자리
		int z = i / 100;//100자리

		if (x == 0 || y == 0 || z == 0) continue;//숫자가 0 인경우
		if ((x == y) || (y == z) || (x == z)) continue;//숫자가 같은경우

		for (int j = 0; j < baseball.size(); j++) {

			int strike = 0;
			int ball = 0;

			int question = baseball[j][0];
			int question_x = question % 10;
			int question_y = (question / 10) % 10;
			int question_z = question / 100;

			//스트라이크 일치 체크
			if (question_x == x) strike++;
			if (question_y == y) strike++;
			if (question_z == z) strike++;
			if (strike != baseball[j][1]) break;

			if (question_x == y || question_x == z) ball++;
			if (question_y == x || question_y == z) ball++;
			if (question_z == x || question_z == y) ball++;
			if (ball != baseball[j][2]) break;

			if (j == baseball.size() - 1) answer++;
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> v;
	vector<int> vv1;
	vector<int> vv2;
	vector<int> vv3;
	vector<int> vv4;

	vv1.push_back(123);
	vv1.push_back(1);
	vv1.push_back(1);

	vv2.push_back(356);
	vv2.push_back(1);
	vv2.push_back(0);

	vv3.push_back(327);
	vv3.push_back(2);
	vv3.push_back(0);

	vv4.push_back(489);
	vv4.push_back(0);
	vv4.push_back(1);

	v.push_back(vv1);
	v.push_back(vv2);
	v.push_back(vv3);
	v.push_back(vv4);

	cout << solution(v) << endl;
	return 0;
}
