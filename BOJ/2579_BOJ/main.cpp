#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	int stair[301];
	int dp[301];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> stair[i];

	dp[0] = stair[0];
	dp[1] = max(stair[1], stair[0]+ stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) 
		dp[i] = stair[i] + max(stair[i - 1] + dp[i - 3], dp[i - 2]);
	
	cout << dp[n - 1];

	return 0;
}