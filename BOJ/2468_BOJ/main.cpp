#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n;
int map[101][101];
bool visited[101][101];
int minH = 101;
int maxH = 0;
int ans = 1;

void bfs(int a, int b, int h) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] <= h) continue;

			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			minH = min(minH, map[i][j]);
			maxH = max(maxH, map[i][j]);
		}
	}

	for (int k = minH; k <= maxH; k++) {
		memset(visited, false, sizeof(visited));
		int size = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j] > k) {
					bfs(i, j, k);
					size++;
				}
			}
		}
		ans = max(ans, size);
	}

	cout << ans << "\n";
	
	return 0;
}