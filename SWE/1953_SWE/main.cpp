#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int ans;
int N, M, R, C, L;
int map[51][51];
bool visited[51][51];

void dfs(int a, int b) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { a,b },1 });
	visited[a][b] = true;
	ans = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (dist == L) continue;

		int nx, ny;
		if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7) {
			// 위 1 2 4 7
			nx = x - 1; ny = y;
			if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6) {
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] > 0 && !visited[nx][ny]) {
					q.push({ { nx,ny },dist + 1 });
					visited[nx][ny] = true;
					ans++;
				}
			}
		}
		if (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6) {
			// 아래 1 2 5 6 
			nx = x + 1; ny = y;
			if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7) {
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] > 0 && !visited[nx][ny]) {
					q.push({ { nx,ny },dist + 1 });
					visited[nx][ny] = true;
					ans++;
				}
			}
		}
		if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5) {
			// 오른쪽 1 3 4 5 
			nx = x; ny = y + 1;
			if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7) {
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] > 0 && !visited[nx][ny]) {
					q.push({ { nx,ny },dist + 1 });
					visited[nx][ny] = true;
					ans++;
				}
			}
		}
		if (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7) {
			// 왼쪽 1 3 6 7
			nx = x; ny = y - 1;
			if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5) {
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] > 0 && !visited[nx][ny]) {
					q.push({ { nx,ny },dist + 1 });
					visited[nx][ny] = true;
					ans++;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		ans = 0;
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				visited[i][j] = false;

		dfs(R, C);

		cout << "#" << T << " " << ans << "\n";
	}

	return 0;
}