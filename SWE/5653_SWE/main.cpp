#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct Cell {
	int state;
	int lifeCycle;
	int activeTime;
	int unactiveTime;
};

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int N, M, K;
Cell map[350][350];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		for (int i = 0; i < 350; i++)
			for (int j = 0; j < 350; j++)
				map[i][j] = { -1, 0, 0, 0 };
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int cycle;
				cin >> cycle;
				if (cycle > 0) 
					map[i + 150][j + 150] = { 0,cycle, cycle, cycle };
			}
		}
			
		int time = 0;
		while (time < K) {
			queue<pair<int, int>> activeCells;
			for (int i = 0; i < 350; i++) {
				for (int j = 0; j < 350; j++) {
					if (map[i][j].state == 0) {
						if (map[i][j].unactiveTime > 0) {
							map[i][j].unactiveTime--;
						}
						if (map[i][j].unactiveTime == 0) {
							map[i][j].state = 1;
						}
					}
					else if (map[i][j].state == 1) {
						if (map[i][j].activeTime > 0) {
							map[i][j].activeTime--;
							activeCells.push({ i,j });
						}
						if (map[i][j].activeTime == 0) {
							map[i][j].state = 2;
						}
					}
				}
			}

			while (!activeCells.empty()) {
				int x = activeCells.front().first;
				int y = activeCells.front().second;
				activeCells.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx >= 350 || ny < 0 || ny >= 350) continue;
					if (map[nx][ny].state < 0) {
						map[nx][ny] = { 0, map[x][y].lifeCycle,map[x][y].lifeCycle ,map[x][y].lifeCycle };
					}
					else if (map[nx][ny].state == 0 && map[nx][ny].lifeCycle == map[nx][ny].unactiveTime) {
						if (map[nx][ny].lifeCycle < map[x][y].lifeCycle) {
							map[nx][ny] = { 0, map[x][y].lifeCycle ,map[x][y].lifeCycle ,map[x][y].lifeCycle };
						}
					}
				}
			}

			time++;
		}

		int ans = 0;
		for (int i = 0; i < 350; i++)
			for (int j = 0; j < 350; j++)
				if (map[i][j].state == 0 || map[i][j].state == 1)
					ans++;
		cout << "#" << T << " " << ans << "\n";
	}

	return 0;
}