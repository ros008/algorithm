#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char str1[1001];
char str2[1001];

int dp[1001][1001];
int i, j;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	scanf("%s %s", str1 + 1, str2 + 1);

	for (i = 1; str1[i]; i++) {
		for (j = 1; str2[j]; j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (str1[i] == str2[j]));
		}
	}
	
	cout << dp[i - 1][j - 1] << '\n';

	return 0;
}