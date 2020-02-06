#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int n, m;
int map[501][501];
bool visited[501][501];
int ans = 0;

void dfs(int x, int y, int sum, int cnt) {

	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[nx][ny]) continue;
		
		visited[nx][ny] = true;
		dfs(nx, ny, sum + map[nx][ny], cnt + 1);
		visited[nx][ny] = false;
	}
}

void tetromino1 (int x, int y) { 
	if (x >= 1 && y >= 1 && y <= m - 2) // ぬ
		ans = max(ans, map[x][y] + map[x - 1][y - 1] + map[x - 1][y] + map[x - 1][y + 1]);
	if (x >= 1 && x <= n - 2 && y >= 1) //た
		ans = max(ans, map[x][y] + map[x - 1][y - 1] + map[x][y - 1] + map[x + 1][y - 1]);
	if (x <= n - 2 && y >= 1 && y <= m - 2) //で
		ans = max(ans, map[x][y] + map[x + 1][y - 1] + map[x + 1][y] + map[x + 1][y + 1]);
	if (x >= 1 && x <= n - 2 && y <= m - 1) // っ
		ans = max(ans, map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, map[i][j], 1);
			tetromino1(i, j);
			visited[i][j] = false;
		}
	}

	cout << ans << "\n";

	return 0;
}