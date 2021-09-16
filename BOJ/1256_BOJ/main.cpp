#include <iostream>
#include <algorithm>

#define MAX 1000000000

using namespace std;

int dp[201][201];


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	long long k;
	cin >> n >> m >> k;
	
	int len = m + n;

	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j], MAX);
		}
	}

	if (dp[m + n][m] < k) {
		cout << -1;
		return 0;
	}

	int cnt = 0;
	while (cnt < len) {
		if (k <= dp[m + n - 1][m]) { // a로 시작
			cout << "a";
			n--;
		}
		else { // z로 시작
			cout << "z";
			k -= dp[m + n - 1][m];
			m--;
		}
		cnt++;
	}

	return 0;
}