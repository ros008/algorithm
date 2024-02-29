#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 400001

using namespace std;

int input, len = 0;
int arr[100001];
int dp[5][5][100001];

int game(int l, int r, int i) {
	if (i == len) 
		return 0;
	
	if (dp[l][r][i] != -1)
		return dp[l][r][i];

	if (l == 0 && r == 0)
		return dp[l][r][i] = game(arr[i], r, i + 1) + 2;

	if (l == arr[i] || r == arr[i])
		return dp[l][r][i] = game(l, r, i + 1) + 1;
	
	int left = 0;
	if (l == 0) {
		left = game(arr[i], r, i + 1) + 2;
	}
	else if (abs(l - arr[i]) == 2) {
		left = game(arr[i], r, i + 1) + 4;
	}
	else {
		left = game(arr[i], r, i + 1) + 3;
	}

	int right = 0;
	if (r == 0) {
		right = game(l, arr[i], i + 1) + 2;
	}
	else if (abs(r - arr[i]) == 2) {
		right = game(l, arr[i], i + 1) + 4;
	}
	else {
		right = game(l, arr[i], i + 1) + 3;
	}

	return min(left, right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> input;
		if (input == 0) break;
		arr[len++] = input;
	}

	memset(dp, -1, sizeof(dp));
	
	cout << game(0, 0, 0) << "\n";

	return 0;
}