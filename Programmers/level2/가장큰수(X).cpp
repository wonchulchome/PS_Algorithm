#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	vector<int> numberByOne;
	for (int i = 0; i < numbers.size(); ++i) {
		if (numbers[i] < 10) {
			numberByOne.push_back(numbers[i]);
		}
		else if (numbers[i] < 100) {
			numberByOne.push_back(numbers[i] / 10);
			numberByOne.push_back(numbers[i] % 10);
		}
		else if (numbers[i] < 1000) {
			numberByOne.push_back(numbers[i] / 100);
			numberByOne.push_back( (numbers[i] / 10) % 10);
			numberByOne.push_back(numbers[i] % 10);
		}
		else {//1000
			numberByOne.push_back(1);
			numberByOne.push_back(0);
			numberByOne.push_back(0);
			numberByOne.push_back(0);
		}
	}
	sort(numberByOne.begin(), numberByOne.end(), greater<int>());
	
	for (int i = 0; i < numberByOne.size(); ++i) {
		answer += (char)numberByOne[i] + '0';
	}

	return answer;
}

int main() {
	vector<int> v1 = { 6, 10, 2 };
	vector<int> v2 = { 3, 30, 35, 5, 9 };
	cout << solution(v1) << endl;
	cout << solution(v2) << endl;
	return 0;
}
