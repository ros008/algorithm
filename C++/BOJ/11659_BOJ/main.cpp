#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, input, sum = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> input;
		sum += input;
		dp[i] = sum;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}

	return 0;
}