#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define INF 987654321

using namespace std;

int n, p;
string onoff;
int baljeon[16][16];
int dp[1 << 16]; // 1<<16 인 상태에서 p만큼이 켜졌을때 드는 최소 비용

int fix(int cnt, int bitmask) {
	if (cnt == p)
		return 0;

	if (dp[bitmask] != -1)
		return dp[bitmask];

	dp[bitmask] = INF;

	for (int i = 0; i < n; i++) {
		if ((bitmask & (1 << i)) == 0) continue; // 켜줄 발전기가 꺼져있으면 패스
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((bitmask & (1 << j)) == 0) // 킬 발전기가 꺼저있을 때만
				dp[bitmask] = min(dp[bitmask], fix(cnt + 1, bitmask | (1 << j)) + baljeon[i][j]);
		}
	}

	return dp[bitmask];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> baljeon[i][j];
	
	cin >> onoff;
	cin >> p;

	int bitmask = 0, cnt = 0;
	for (int i = 0; i < onoff.length(); i++) {
		if (onoff[i] == 'Y') {
			bitmask |= (1 << i);
			cnt++;
		}
	}
	
	memset(dp, -1, sizeof(dp));

	if (cnt >= p)
		cout << "0\n";
	else if (cnt == 0 && p > 0)
		cout << "-1\n";
	else
		cout << fix(cnt, bitmask) << "\n";

	return 0;
}