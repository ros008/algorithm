#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1025][1025];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			dp[i + 1][j + 1] = input + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}