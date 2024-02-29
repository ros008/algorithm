#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int N, ans = INF;
int map[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	map[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (map[nx][ny] > 0 && !visited[nx][ny]) {
				dfs(nx, ny, cnt);
			}
		}
	}
}

int bfs(int cnt) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == cnt) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}

	int len = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] > 0 && map[nx][ny] != cnt) {
						return len;
					}
					else if (map[nx][ny] == 0 && !visited[nx][ny]) {
						q.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
		len++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	int cnt = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] > 0 && !visited[i][j])
				dfs(i, j, cnt++);

	for (int i = 1; i < cnt; i++) {
		memset(visited, false, sizeof(visited));
		ans = min(ans, bfs(i));
	}

	cout << ans << "\n";
	
	return 0;
}