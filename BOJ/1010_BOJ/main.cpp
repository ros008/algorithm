#include <iostream>

using namespace std;

const int MAX = 30;

int dp[MAX + 1][MAX + 1];

void go() {
	for (int i = 0; i <= MAX; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	int n, m;
	
	cin >> tc;
	
	go();

	while (tc--) {
		cin >> n >> m;
		cout << dp[m][n] << "\n";
	}

	return 0;
}