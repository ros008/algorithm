#include <iostream>
#include <algorithm>

using namespace std;

int n, m, s, e;
int arr[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;

	for (int i = 1; i <= n - 1; i++)
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;

	for (int len = 3; len <= n; len++) 
		for (int i = 1; i <= n - len + 1; i++) 
			if (arr[i] == arr[i + len - 1] && dp[i + 1][i + len - 2])
				dp[i][i + len - 1] = 1;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}

	return 0;
}