#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[4001][4001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	int maxLen = 0;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = 0;
			maxLen = max(maxLen, dp[i + 1][j + 1]);
		}
	}

	cout << maxLen;

	return 0;
}