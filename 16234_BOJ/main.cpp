#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int n, l, r;
int map[51][51];
bool visited[51][51];
vector<pair<int, int>> v;
int moveCnt = 0, people;

void bfs(int a, int b) {
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
			int diff = abs(map[x][y] - map[nx][ny]);
			if (l <= diff && diff <= r && !visited[nx][ny]) {
				visited[nx][ny] = true;
				v.push_back({ nx,ny });
				people += map[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	while (1) {
		memset(visited, false, sizeof(visited));

		bool found = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;

				visited[i][j] = true;
				people = map[i][j];

				v.clear();
				v.push_back({ i,j });
				bfs(i, j);

				if (v.size() >= 2) {
					found = true;
					for (int k = 0; k < v.size(); k++)
						map[v[k].first][v[k].second] = people / (int)v.size();
				}
			}
		}

		if (found) {
			moveCnt++;
		}
		else {
			break;
		}
	}

	cout << moveCnt << "\n";

	return 0;
}