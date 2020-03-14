#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int INF = 987654321;

int D, W, K, ans;
int map[20 + 1][13 + 1];

void checkAbility(int cntChemi) {
	for (int j = 0; j < W; j++) {
		int cnt = 1;	
		for (int i = 0; i < D - 1; i++) {
			if (cnt >= K)
				break;
			if (map[i][j] == map[i + 1][j])
				cnt++;
			else
				cnt = 1;
		}
		if (cnt < K) return;
	}
	if (ans > cntChemi)
		ans = cntChemi;
}

void dfs(int d, int cnt) {
	
	if (d >= D) {
		checkAbility(cnt);
		return;
	}
	
	// 안 넣는다
	dfs(d + 1, cnt);

	// A 넣는다
	int tmp[20 + 1];
	for (int i = 0; i < W; i++)	
		tmp[i] = map[d][i];
	for (int i = 0; i < W; i++) 
		map[d][i] = 0;
	dfs(d + 1, cnt + 1);
	for (int i = 0; i < W; i++) 
		map[d][i] = tmp[i];

	// B 넣는다
	for (int i = 0; i < W; i++)
		tmp[i] = map[d][i];
	for (int i = 0; i < W; i++)
		map[d][i] = 1;
	dfs(d + 1, cnt + 1);
	for (int i = 0; i < W; i++)
		map[d][i] = tmp[i];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> D >> W >> K;
		ans = INF;
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];

		dfs(0, 0);

		cout << "#" << T << " " << ans << "\n";
	}

	return 0;
}