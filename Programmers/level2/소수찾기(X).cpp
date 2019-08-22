#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool check[10000000];

bool isPrimeNumber(int num) {
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	if (num == 1) return false;
	int rootNum = (int)sqrt(num);
	for (int i = 3; i <= rootNum; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	//벡터에 모든 숫자 넣기
	vector<int> allNum;
	for (int i = 0; i < numbers.length(); i++) {
		allNum.push_back(numbers.at(i) - '0');
	}

	//모든 조합 구하기
	vector<int> ind;//0과 1을 저장할 벡터
	for (int i = 1; i <= numbers.length(); i++) {
		int k = i;
		//k개의 1추가
		for (int j = 0; j < k; j++) {
			ind.push_back(1);
		}
		//(숫자의 개수 - k)의 0 추가
		for (int j = 0; j < numbers.length() - k; j++) {
			ind.push_back(0);
		}
		//정렬
		sort(ind.begin(), ind.end());
		//숫자 nCr 그룹
		vector<int> group;

		do{
			for (int j = 0; j < ind.size(); j++) {
				if (ind[j] == 1) {
					group.push_back(allNum[j]);
				}
			}
			//순열
			do{
				string str = "";
				for (int j = 0; j < group.size(); j++) {
					str += (char)(group[j] + (int)'0');
				}
				if (isPrimeNumber(atoi(str.c_str()))) {
					if (!check[atoi(str.c_str())]) {
						check[atoi(str.c_str())] = true;
						answer++;
					}
				}
			} while(next_permutation(group.begin(), group.end()));
			group.clear();
		} while (next_permutation(ind.begin(), ind.end()));
		ind.clear();
	}
	for (int i = 0; i < 10000000; ++i) {
		check[i] = false;
	}
	return answer;
}

int main() {
	string str1 = "17";
	string str2 = "011";
	string str3 = "4";
	string str4 = "1276543";
	string str5 = "9999999";

	cout << solution(str1) << endl;
	cout << solution(str2) << endl;
	cout << solution(str3) << endl;
	cout << solution(str4) << endl;
	cout << solution(str5) << endl;

	return 0;
}

//input 1276543일때 output 1336 나와야함..
// (문제출처)http://2009.nwerc.eu/results/nwerc09.pdf
