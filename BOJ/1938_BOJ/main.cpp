#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { -1,-1,-1,0,0,1,1,1 };
const int dy[] = { -1,0,1,-1,1,-1,0,1 };

int n, Bshape, Eshape;
char map[51][51];
bool visited[51][51][2];
vector<pair<int, int>> B, E;
pair<int, int> Bcenter, Ecenter;

bool canTurn(int x, int y, int s) {
	if (s == 0) { // ㅡ
		for (int i = 0; i < 8; i++) {
			if (i == 3 || i == 4) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
			if (map[nx][ny] == '1') return false;
		}
	}
	else if (s == 1) { // ㅣ
		for (int i = 0; i < 8; i++) {
			if (i == 1 || i == 6) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
			if (map[nx][ny] == '1') return false;
		}
	}

	return true;
}

int bfs(int a, int b) {
	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {a,b}, {Bshape, 0} });
	visited[a][b][Bshape] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int shape = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == Ecenter.first && y == Ecenter.second && shape == Eshape)
			return cnt;

		if (shape == 0) {
			// up
			int nx = x - 1;
			int ny = y;
			if (nx >= 0 && !visited[nx][ny][shape]) {
				if (map[nx][ny] == '0' && map[nx][ny - 1] == '0' && map[nx][ny + 1] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// down
			nx = x + 1;
			ny = y;
			if (nx < n && !visited[nx][ny][shape]) {
				if (map[nx][ny] == '0' && map[nx][ny - 1] == '0' && map[nx][ny + 1] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// left
			nx = x;
			ny = y - 1;
			if (ny - 1 >= 0 && !visited[nx][ny][shape]) {
				if (map[nx][ny - 1] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// right
			nx = x;
			ny = y + 1;
			if (ny + 1 < n && !visited[nx][ny][shape]) {
				if (map[nx][ny + 1] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// turn
			if (canTurn(x, y, shape) && !visited[x][y][1]) {
				visited[x][y][1] = true;
				q.push({ {x,y}, {1, cnt + 1} });
			}
		}
		else if (shape == 1) {
			// up
			int nx = x - 1;
			int ny = y;
			if (nx - 1 >= 0 && !visited[nx][ny][shape]) {
				if (map[nx - 1][ny] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// down
			nx = x + 1;
			ny = y;
			if (nx + 1 < n && !visited[nx][ny][shape]) {
				if (map[nx + 1][ny] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// left
			nx = x;
			ny = y - 1;
			if (ny >= 0 && !visited[nx][ny][shape]) {
				if (map[nx][ny] == '0' && map[nx - 1][ny] == '0' && map[nx + 1][ny] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// right
			nx = x;
			ny = y + 1;
			if (ny < n && !visited[nx][ny][shape]) {
				if (map[nx][ny] == '0' && map[nx - 1][ny] == '0' && map[nx + 1][ny] == '0') {
					visited[nx][ny][shape] = true;
					q.push({ {nx,ny}, {shape, cnt + 1} });
				}
			}

			// turn
			if (canTurn(x, y, shape) && !visited[x][y][0]) {
				visited[x][y][0] = true;
				q.push({ {x,y}, {0, cnt + 1} });
			}
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				B.push_back({ i,j });
				map[i][j] = '0';
			}
			else if (map[i][j] == 'E') {
				E.push_back({ i,j });
				map[i][j] = '0';
			}
		}
	}
	Bcenter.first = B[1].first;
	Bcenter.second = B[1].second;
	Ecenter.first = E[1].first;
	Ecenter.second = E[1].second;

	// B E 모양 결정  누운 모양이 0, 선 모양이 1
	if (B[0].first == B[1].first && B[1].first == B[2].first) Bshape = 0;
	else Bshape = 1;
	if (E[0].first == E[1].first && E[1].first == E[2].first) Eshape = 0;
	else Eshape = 1;

	cout << bfs(Bcenter.first, Bcenter.second) << "\n";

	return 0;
}