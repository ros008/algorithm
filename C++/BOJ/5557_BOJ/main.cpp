#include <iostream>
#include <vector>

using namespace std;

long long dp[101][21] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, input;

	cin >> n;
	cin >> input;

	dp[1][input]++;
	for (int i = 2; i <= n; i++) {
		cin >> input;
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + input <= 20) dp[i][j + input] += dp[i - 1][j];
				if (j - input >= 0)dp[i][j - input] += dp[i - 1][j];
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 20; j++) {
			cout << dp[i][j] << "  ";
		}
		cout << "\n";
	}

	cout << dp[n - 1][input];

	return 0;
}