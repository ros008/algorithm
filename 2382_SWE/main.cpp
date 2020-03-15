#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct Bacteria {
	int x;
	int y;
	int num;
	int dir;
};

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

int N, M, K;
int map[100 + 1][100 + 1][2];
Bacteria bacterias[1000 + 1];

int changeDir(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else return 3;
}

void moveBacteria() {
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= K; i++) {
		if (bacterias[i].num == 0) continue;

		int ndir = bacterias[i].dir;
		int nx = bacterias[i].x + dx[ndir];
		int ny = bacterias[i].y + dy[ndir];
		bacterias[i].x = nx;
		bacterias[i].y = ny;

		// 경계에 닿으면
		if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
			bacterias[i].num >>= 1;
			bacterias[i].dir = changeDir(ndir);
		}

		// 다른 미생물과 만나면
		if (map[nx][ny][0] != 0) {
			int idx = map[nx][ny][0];

			bacterias[idx].num += bacterias[i].num;

			if (map[nx][ny][1] < bacterias[i].num) {
				map[nx][ny][1] = bacterias[i].num;
				bacterias[idx].dir = bacterias[i].dir;
			}

			bacterias[i].num = 0;
		}
		else {
			map[nx][ny][0] = i;
			map[nx][ny][1] = bacterias[i].num;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> N >> M >> K;
		for (int i = 1; i <= K; i++) {
			int x, y, n, d;
			cin >> x >> y >> n >> d;
			bacterias[i] = { x,y,n,d };
		}
		for (int i = 0; i < M; i++) {
			moveBacteria();
		}

		int total = 0;
		for (int i = 1; i <= K; i++) {
			total += bacterias[i].num;
		}
		cout << "#" << T << " " << total << "\n";
	}

	return 0;
}