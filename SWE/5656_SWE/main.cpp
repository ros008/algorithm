#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

#define INF 200

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int N, W, H;
int map[15][12];
int minCnt;

void copyMap(int map[15][12], int newMap[15][12]) {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			newMap[i][j] = map[i][j];
}

void getDown(int map[15][12]) {
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (map[i][j] != 0) continue;

			for (int k = i - 1; k >= 0; k--) {
				if (map[k][j] == 0) continue;
				map[i][j] = map[k][j];
				map[k][j] = 0;
				break;
			}
		}
	}
}

void boom(int r, int c, int map[15][12]) {
	queue <pair<int, int>> q;
	q.push({ r,c });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int num = map[x][y];
		q.pop();

		map[x][y] = 0;

		if (num == 1) continue;

		for (int i = 0; i < 4; i++) {
			for (int k = 1; k < num; k++) {
				int nx = x + dx[i] * k;
				int ny = y + dy[i] * k;

				if (nx < 0 || nx >= H || ny < 0 || ny >= W) break;

				if (map[nx][ny] > 1) q.push({ nx,ny });
				else map[nx][ny] = 0;
			}
		}
	}
}

void game(int n, int map[15][12]) {
	if (n == N) {
		int cnt = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (map[i][j] != 0)
					cnt++;
		if (minCnt > cnt) 
			minCnt = cnt;
		return;
	}

	for (int i = 0; i < W; i++) {
		int x = 0, y = i;
		while (1) {
			if (x >= H) break;
			if (map[x][y] != 0) break;
			x++;
		}

		if (x >= H) continue;
		
		int newMap[15][12];
		copyMap(map, newMap);

		boom(x, y, newMap);
		getDown(newMap);
		game(n + 1, newMap);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		minCnt = INF;
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];

		game(0, map); 
		cout << "#" << T << " " << (minCnt == 200 ? 0 : minCnt) << "\n";
	}

	return 0;
}