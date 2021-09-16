#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	char ans[1001];
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}

	int i = str1.length(), j = str2.length();
	int len = dp[i][j];
	ans[len] = '\0';
	while (1) {
		if (len == 0) break;
		if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i - 1][j] == dp[i][j - 1]) {
			len--;
			ans[len] = str1[i - 1];
			i--; j--;
		}
	}

	i = str1.length(), j = str2.length();
	cout << dp[i][j] << "\n";
	cout << ans << "\n";

	return 0;
}