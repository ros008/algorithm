#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m;
char map[51][51];
bool visited[51][51];
int maxLen = 0;

void dfs(int a, int b) {
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {a,b},0 });
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curLen = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] != 'L') continue;

			q.push({ {nx, ny}, curLen + 1 });
			visited[nx][ny] = true;
			maxLen = max(maxLen, curLen + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				dfs(i, j);
			}
		}
	}
	
	cout << maxLen << "\n";

	return 0;
}