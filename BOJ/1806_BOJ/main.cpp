#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> arr(N + 1);
	vector<int> dp(N + 1 , 0);

	int  minLen = 100000000;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
	}

	bool found = false;

	int i = 0, j = 1;
	while (i < j && i<=N && j<=N) {
		if (dp[j] - dp[i] >= S) {
			minLen = min(minLen, j - i);
			i++;
			found = true;
		}
		else j++;
	}

	if (!found) cout << 0;
	else cout << minLen;

	return 0;
}