#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1000000007;

using namespace std;

int dp[501][501];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int N; 
	cin >> N;
	vector<pair<int, int>> arr(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j + i <= N; j++) {
			int x = j;
			int y = i + j;
			
			dp[x][y] = INF;
			
			for (int k = x; k < y; k++) {
				dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y] + arr[x].first * arr[k].second * arr[y].second);
			}
		}
	}

	cout << dp[1][N] << '\n';

	return 0;
}