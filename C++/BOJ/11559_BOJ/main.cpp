#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

char map[12][6];
bool visited[12][6];
int ans = 0;

void puyoDown() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] != '.') {
				for (int k = 11; k > i; k--) {
					if (map[k][j] == '.') {
						char tmp = map[k][j];
						map[k][j] = map[i][j];
						map[i][j] = tmp;
						break;
					}
				}
			}
		}
	}
}

int puyoBomb(int a, int b) {
	int cnt = 0;
	vector<pair<int, int>> crash;
	queue<pair<int, int>> q;

	char color = map[a][b];

	q.push({ a,b });
	visited[a][b] = true;
	crash.push_back({ a,b });
	cnt++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] != color) continue;

			q.push({ nx, ny });
			visited[nx][ny] = true;
			crash.push_back({ nx, ny });
			cnt++;
		}
	}
	
	if (cnt >= 4) {
		for (int i = 0; i < crash.size(); i++) 
			map[crash[i].first][crash[i].second] = '.';
		return cnt;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];

	while (1) {
		memset(visited, false, sizeof(visited));
		int ret = 0;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if(map[i][j] != '.')
					ret = max(ret, puyoBomb(i, j));
			}
		}
		puyoDown();

		if (ret) ans++;
		else break;
	}

	cout << ans << "\n";

	return 0;
}