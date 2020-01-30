#include <iostream>
#include <algorithm>

using namespace std;

int n;
int tp[15 + 3][2];
int dp[15 + 3];
int curMax = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> tp[i][0] >> tp[i][1];
	
	for (int i = n; i > 0; i--) {
		if ((tp[i][0] + i - 1) > n) 
			dp[i] = max(curMax, 0);
		else {
			dp[i] = max(tp[i][1]+ dp[i+tp[i][0]], curMax);
			curMax = max(curMax, dp[i]);
		}
	}

	cout << dp[1] << "\n";

	return 0;
}