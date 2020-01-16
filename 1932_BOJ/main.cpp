#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tri[501][501];
int dp[501][501];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j <= i; j++) 
			cin >> tri[i][j];
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (i == n - 1) dp[i][j] = tri[i][j];
			else dp[i][j] = tri[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	cout << dp[0][0];

	return 0;
}