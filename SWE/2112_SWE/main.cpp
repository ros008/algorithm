#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

#define INF 987654321

using namespace std;

int D, W, K;
int minChemicalCnt;
int map[13 + 1][20 + 1];
int chemical[13 + 1];

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
	if (minChemicalCnt > cntChemi)
		minChemicalCnt = cntChemi;
}

void dfs(int d, int cnt) {
	if (cnt > minChemicalCnt)
		return;
	if (d >= D) {
		checkAbility(cnt);
		return;
	}

	// d번째 줄에 안뿌린다
	dfs(d + 1, cnt);

	// d번째 줄에 A를 뿌린다
	int tmp[20 + 1];
	for (int i = 0; i < W; i++)
		tmp[i] = map[d][i];
	for (int i = 0; i < W; i++)
		map[d][i] = 0;
	dfs(d + 1, cnt + 1);
	for (int i = 0; i < W; i++)
		map[d][i] = tmp[i];

	// d번째 줄에 B를 뿌린다
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
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];
		minChemicalCnt = K;
		dfs(0, 0);

		cout << "#" << T << " " << minChemicalCnt << "\n";
	}

	return 0;
}