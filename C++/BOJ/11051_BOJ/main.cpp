#include <iostream>

using namespace std;

const int MOD = 10007;

int result[1000 + 1][1000 + 1];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) result[i][j] = 1;
			else result[i][j] = (result[i - 1][j - 1] + result[i - 1][j]) % MOD;
		}
	}

	cout << result[n][k];

	return 0;
}
