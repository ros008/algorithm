#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

// dp[i][h] i번째 재단까지 생각했을 때, 높이가 h가 되는 경우의 수
// 메모리 문제로 dp 2개만 사용해서 슬라이딩 윈도우
long long dp[2][5003];
int arr[10001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0][0] = arr[1] == -1 ? 1 : arr[1] == 0 ? 1 : 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == -1) {
			for (int j = 0; j <= n / 2; j++)
				dp[1][j] = (((j - 1) < 0 ? 0 : dp[0][j - 1]) + dp[0][j] + dp[0][j + 1]) % MOD;
		}
		else {
			dp[1][arr[i]] = (((arr[i] - 1) < 0 ? 0 : dp[0][arr[i] - 1]) + dp[0][arr[i]] + dp[0][arr[i] + 1]) % MOD;
		}

		for (int j = 0; j <= n / 2; j++) {
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
	}

	cout << dp[0][0] << "\n";

	return 0;
}