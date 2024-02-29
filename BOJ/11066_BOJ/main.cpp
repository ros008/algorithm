#include <iostream>
#include <algorithm>

#define INF 1000000007;
using namespace std;

int dp[501][501];
int sums[501];
int filesize[501];
int K;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int tc; cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> K;

		for (int i = 1; i <= K; i++) {
			cin >> filesize[i];
			sums[i] = sums[i - 1] + filesize[i];
		}

		for (int i = 1; i <= K; i++) {
			for (int j = 1; j + i <= K; j++) {
				int x = j;
				int y = j + i;

				dp[x][y] = INF;

				for (int k = x; k < y; k++) {
					dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y] + sums[y] - sums[x - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
	}

	return 0;
}