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
	visited[x][y] = true; 
	
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[nx][ny]) continue;

		dfs(nx, ny, sum + map[nx][ny], cnt + 1);
		visited[nx][ny] = false;
	}
}

void tetromino1 (int x, int y) { // ぬ
	int sum = 0;
	sum += (map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
	ans = max(ans, sum);
}
void tetromino2 (int x, int y) { // た
	int sum = 0;
	sum += (map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1]);
	ans = max(ans, sum);
}
void tetromino3 (int x, int y) { // で
	int sum = 0;
	sum += (map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1]);
	ans = max(ans, sum);
}
void tetromino4 (int x, int y) { // っ
	int sum = 0;
	sum += (map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1]);
	ans = max(ans, sum);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, false, sizeof(visited));
			dfs(0, 0, 0, 1);
			if (i <= n - 2 && j <= m - 3) tetromino1(i, j);
			if (i <= n - 3 && j <= m - 2) tetromino2(i, j);
			if (i >= 1 && j <= m - 3) tetromino3(i, j);
			if (i <= n - 3 && j >= 1) tetromino4(i, j);
		}
	}

	cout << ans << "\n";

	return 0;
}