#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { 0,1,1 }; // ㅡ ㅣ 대각선
const int dy[] = { 1,0,1 };

int n, ans = 0;
int map[17][17];

void bfs() {
	queue < pair<pair<int, int>, int>> q;
	q.push({ {1,2}, 0 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		if (x == n && y == n) {
			ans++;
			continue;
		}

		if (dir == 0) { // ㅡ
			// ㅡ
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0) {
					q.push({ {nx, ny}, dir });
				}
			}

			// 대각선
			nx = x + dx[2];
			ny = y + dy[2];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0 && map[x + 1][y] == 0 && map[x][y + 1] == 0) {
					q.push({ {nx, ny}, 2 });
				}
			}
		}
		else if (dir == 1) { // ㅣ
			// ㅣ
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0) {
					q.push({ {nx,ny}, dir });
				}
			}

			nx = x + dx[2];
			ny = y + dy[2];
			// 대각선
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0 && map[x + 1][y] == 0 && map[x][y + 1] == 0) {
					q.push({ {nx, ny}, 2 });
				}
			}
		}
		else if (dir == 2) { // 대각선
			// 대각선
			int nx = x + dx[2];
			int ny = y + dy[2];
			// 대각선
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0 && map[x + 1][y] == 0 && map[x][y + 1] == 0) {
					q.push({ {nx, ny}, 2 });
				}
			}
			
			// ㅡ
			nx = x + dx[0];
			ny = y + dy[0];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0) {
					q.push({ {nx, ny}, 0 });
				}
			}

			// ㅣ
			nx = x + dx[1];
			ny = y + dy[1];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
				if (map[nx][ny] == 0) {
					q.push({ {nx,ny}, 1 });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	bfs();

	cout << ans << "\n";

	return 0;
}