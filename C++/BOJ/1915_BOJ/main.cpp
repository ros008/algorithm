#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, maxLen = 0;
	char input;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input;
			if (input == '1') {
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j],dp[i - 1][j - 1])) + 1;
				maxLen = dp[i][j] > maxLen ? dp[i][j] : maxLen;
			}
		}
	}


	cout << maxLen * maxLen;

	return 0;
}