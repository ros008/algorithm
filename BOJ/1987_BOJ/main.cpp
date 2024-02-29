#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int r, c;
char map[21][21];
bool alpha[26];
int ans = 1;

void bfs(int x, int y, int cnt) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (alpha[map[nx][ny] - 'A']) continue;
		
		alpha[map[nx][ny] - 'A'] = true;
		bfs(nx, ny, cnt + 1);
		alpha[map[nx][ny] - 'A'] = false;
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	alpha[map[0][0] - 'A'] = true;
	bfs(0, 0, ans);

	cout << ans << "\n";

	return 0;
}