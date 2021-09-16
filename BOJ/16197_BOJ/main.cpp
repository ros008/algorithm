#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m;
int moveCnt = 987654321;
char map[21][21];
vector<pair<int, int>> coin;

bool overRangeCheck(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return true;
	return false;
}

void moveCoin(int x, int y, int xx, int yy, int cnt, int dir) {
	if (moveCnt < cnt) return;
	if (cnt > 10) {
		moveCnt = min(moveCnt, cnt);
		return;
	}

	int nx = x + dx[dir];
	int ny = y + dy[dir];
	int nxx = xx + dx[dir];
	int nyy = yy + dy[dir];

	if (overRangeCheck(x, y) && overRangeCheck(xx, yy)) return;
	else if (overRangeCheck(x, y) && !overRangeCheck(xx, yy)) {
		moveCnt = min(moveCnt, cnt);
		return;
	}
	else if (!overRangeCheck(x, y) && overRangeCheck(xx, yy)) {
		moveCnt = min(moveCnt, cnt);
		return;
	}

	if (map[nx][ny] == '#') {
		nx = x;
		ny = y;
	}
	if (map[nxx][nyy] == '#') {
		nxx = xx;
		nyy = yy;
	}

	for (int i = 0; i < 4; i++) {
		moveCoin(nx, ny, nxx, nyy, cnt + 1, i);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') coin.push_back({ i,j });
		}
	}
		
	for (int i = 0; i < 4; i++) {
		int x = coin[0].first;
		int y = coin[0].second;
		int xx = coin[1].first;
		int yy = coin[1].second;

		moveCoin(x, y, xx, yy, 0, i);
	}

	if (moveCnt > 10) moveCnt = -1;
	cout << moveCnt << "\n";

	return 0;
}