#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int* arr;
int ans;
int N;
int B;

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d",&N, &B);

		arr = new int[N];

		for (int i = 0; i < N; ++i) {
			scanf("%d", &arr[i]);
		}

		ans = 100000;

		for (int i = 1; i < N; ++i) {

			vector<int> combi;

			for (int j = 0; j <= i; ++j) {
				combi.push_back(1);
			}

			for (int j = 0; j <= N - i; ++j) {
				combi.push_back(0);
			}

			sort(combi.begin(), combi.end());
			int total;
			do {
				total = 0;
				//printf("%d",combi.size());
				for (int j = 0; j < combi.size(); ++j) {
					if (combi[j] == 1) {
						total += arr[j];
					}
				}
				if (total >= B) {
					if (total < ans) {
						ans = total;
					}
				}
			} while (next_permutation(combi.begin(), combi.end()));
		}

		printf("#%d %d\n",tc, ans-B);
	}

	return 0;
}

/*처음에 계산 안해보고, 무조건 터진다고 생각했다.
하지만 1C20 ~ 20C20 다해보면 터지지 않는 것을 알고, 
모든 경우의 조합을 구해서 계산함 */
