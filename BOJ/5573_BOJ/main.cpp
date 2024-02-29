#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000;

int h, w, n;
int dp[MAX + 1][MAX + 1];
int map[MAX + 1][MAX + 1];

int i, j;

void dfs(int r, int c) {
	if (r >= h || c >= w) {
		i = r; j = c;
		return;
	}

	if (map[r][c] == 1) {
		if (dp[r][c] == 1)
			dfs(r, c + 1);
		else
			dfs(r + 1, c);
	}
	else {
		if (dp[r][c] == 1)
			dfs(r + 1, c);
		else
			dfs(r, c + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w >> n;

	for (int i = 0; i < h; i++) 
		for (int j = 0; j < w; j++) 
			cin >> map[i][j];
	
	dp[0][0] = n;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) {
				dp[i + 1][j] += dp[i][j] / 2;
				dp[i][j + 1] += (dp[i][j] % 2 == 0) ? dp[i][j] / 2 : dp[i][j] / 2 + 1;
			}
			else {
				dp[i + 1][j] += (dp[i][j] % 2 == 0) ? dp[i][j] / 2 : dp[i][j] / 2 + 1; 
				dp[i][j + 1] += dp[i][j] / 2;
			}
		}
	}
		
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			dp[i][j] %= 2;

	dfs(0, 0);

	cout << ++i << " " << ++j << "\n";

	return 0;
}