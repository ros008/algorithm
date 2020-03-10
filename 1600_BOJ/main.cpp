#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 200;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

const int dx2[] = { -1,-2,-2,-1,1,2,2,1 };
const int dy2[] = { -2,-1,1,2,2,1,-1,-2 };

int K, W, H;
int map[MAX][MAX];
bool visited[MAX][MAX][31];

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>>> q; // »ç¿ëÇÑk°³¼ö, ÀÌµ¿ È½¼ö,xÁÂÇ¥, yÁÂÇ¥
	q.push({ { 0,0 }, { 0,0 } });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int usedK = q.front().first.first;
		int moveCnt = q.front().first.second;
		q.pop();

		if (x == H - 1 && y == W - 1)
			return moveCnt;

		if (usedK < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx2[i];
				int ny = y + dy2[i];
				if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
					if (map[nx][ny] == 0 && !visited[nx][ny][usedK + 1]) {
						q.push({ {usedK + 1, moveCnt + 1}, {nx, ny} });
						visited[nx][ny][usedK + 1] = true;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (map[nx][ny] == 0 && !visited[nx][ny][usedK]) {
					q.push({ {usedK, moveCnt + 1}, {nx, ny} });
					visited[nx][ny][usedK] = true;
				}
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];

	int ans = bfs();
	cout << ans << "\n";

	return 0;
}