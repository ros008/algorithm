#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int arr[1001];
int dp[2][1001][1001]; // dp[turn][가장 왼쪽][가장 오른쪽]

int game(bool myturn, int l, int r) {
	if (l == r) 
		return myturn ? arr[l] : 0;
	
	if (dp[myturn][l][r] != -1) 
		return dp[myturn][l][r];
	
	if (myturn)
		dp[myturn][l][r] = max(game(!myturn, l + 1, r) + arr[l], game(!myturn, l, r - 1) + arr[r]);
	else
		dp[myturn][l][r] = min(game(!myturn, l + 1, r), game(!myturn, l, r - 1));

	return dp[myturn][l][r];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> n;

		for (int i = 0; i < n; i++) 
			cin >> arr[i];
	
		memset(dp, -1, sizeof(dp));
		
		cout << game(1, 0, n - 1) << "\n";
	}

	return 0;
}