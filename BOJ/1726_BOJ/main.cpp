#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { 0,0,0,1,-1 };
const int dy[] = { 0,1,-1,0,0 };

int m, n;
int map[101][101];
bool visited[101][101][5];
pair<pair<int, int>, int> s, e;

int changeDir(int d, char c) {
	if (c == 'L') {
		if (d == 1) return 4;
		else if (d == 2) return 3;
		else if (d == 3) return 1;
		else if (d == 4) return 2;
	}
	else if (c == 'R') {
		if (d == 1) return 3;
		else if (d == 2) return 4;
		else if (d == 3) return 2;
		else if (d == 4) return 1;
	}
}

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {s.first.first, s.first.second},{s.second, 0} });
	visited[s.first.first][s.first.second][s.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		// cout << x << " " << y << " " << dir << " " << cnt << "\n";

		if (x == e.first.first && y == e.first.second && dir == e.second)
			return cnt;

		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;

			if (visited[nx][ny][dir]) 
				continue;

			if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && map[nx][ny] == 0) {
				visited[nx][ny][dir] = true;
				q.push({ {nx, ny},{dir, cnt + 1} });
			}
			else 
				break;
		}

		int nd;
		nd = changeDir(dir, 'L');
		if (!visited[x][y][nd]) {
			visited[x][y][nd] = true;
			q.push({ {x,y},{nd, cnt + 1} });
		}
		nd = changeDir(dir, 'R');
		if (!visited[x][y][nd]) {
			visited[x][y][nd] = true;
			q.push({ {x,y},{nd, cnt + 1} });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	cin >> s.first.first >> s.first.second >> s.second;
	cin >> e.first.first >> e.first.second >> e.second;

	cout << bfs() << "\n";

	return 0;
}