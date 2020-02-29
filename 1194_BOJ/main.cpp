#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m;
char map[51][51];
bool visited[64][51][51];
pair<int, int> start;

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {start.first, start.second}, {0,0} });
	visited[0][start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second.first;
		int key = q.front().second.second;
		q.pop();

		if (map[x][y] == '1')
			return dist;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == '#' || visited[key][nx][ny]) continue;

			if ('A' <= map[nx][ny] && map[nx][ny] <= 'F'){
				if (key & (1 << (map[nx][ny] - 'A'))) {
					visited[key][nx][ny] = true;
					q.push({ {nx,ny},{dist + 1, key} });
				}
			}
			else if ('a' <= map[nx][ny] && map[nx][ny] <= 'f'){
				int nKey = key | (1 << (map[nx][ny] - 'A'));
				if (!visited[nKey][nx][ny]) {
					visited[key][nx][ny] = true;
					visited[nKey][nx][ny] = true;
					q.push({ {nx,ny},{dist + 1, nKey} });
				}
			}
			else {
				visited[key][nx][ny] = true;
				q.push({ {nx, ny},{dist + 1, key} });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				start = { i,j };
				map[i][j] = '.';
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}