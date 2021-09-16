#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

const int n = 10;
int ans = INF, cnt = 0;
int map[10][10];
int paper[6] = { 0,5,5,5,5,5 };

void coverPaper(int x, int y) {
	if (y == n) {
		coverPaper(x + 1, 0);
		return;
	}

	if (x == n) {
		ans = min(ans, cnt);
		return;
	}

	if (map[x][y] == 0) {
		coverPaper(x, y + 1);
		return;
	}

	for (int len = 5; len >= 1; len--) {
		if (paper[len] == 0 || x + len > n || y + len > n) 
			continue;

		bool hasRec = true;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (map[x + i][y + j] == 0) {
					hasRec = false;
					break;
				}
			}
			if (!hasRec) break;
		}

		if (!hasRec) continue;

		for (int i = 0; i < len; i++) 
			for (int j = 0; j < len; j++) 
				map[x + i][y + j] = 0;
		paper[len]--;
		cnt++;

		coverPaper(x, y + len);

		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				map[x + i][y + j] = 1;
		paper[len]++;
		cnt--;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	coverPaper(0, 0);


	if (ans == INF) cout << -1 << "\n";
	else cout << ans << "\n";

	return 0;
}