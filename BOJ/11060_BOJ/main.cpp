#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int dp[1001]; 
int arr[1001];
int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = n;
	}		

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= arr[i] && i + j < n; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	if (dp[n - 1] == n)
		cout << -1 << "\n";
	else
		cout << dp[n - 1] << "\n";

	return 0;
}