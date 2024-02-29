#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

char roomMap[1001][1001];
int dist[1001][1001][2]; // 2绰 寒阑 何渐绰瘤 0救何见 1何见.
int n, m;

int bfs() {
	queue<pair<pair<int, int>, int>> q; // x, y, w
	q.push({ {0,0},0 });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int w = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1) return dist[x][y][w];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny][w]) continue;

			if (roomMap[nx][ny] == '0') {
				dist[nx][ny][w] = dist[x][y][w] + 1;
				q.push({ {nx,ny},w });
			}
			if (roomMap[nx][ny] == '1' && w == 0) {
				dist[nx][ny][1] = dist[x][y][w] + 1;
				q.push({ {nx,ny},1 });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> roomMap[i][j];
		
	cout << bfs();

	return 0;
}