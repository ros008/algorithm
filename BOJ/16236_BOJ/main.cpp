#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define max_int 21
#define max_val 401

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int n;
int sea[21][21];
int dist[21][21];
int min_x, min_y, min_dist, moveDist = 0;
pair<int, int> babyShark;
int babySharkSize = 2;
int eatCnt = 0;

void init() {
	min_x = max_int;
	min_y = max_int;
	min_dist = max_val;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dist[i][j] = -1;
}

void bfs() {

	queue<pair<int, int>> q;
	dist[babyShark.first][babyShark.second] = 0;
	q.push({ babyShark.first, babyShark.second });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] != -1 || sea[nx][ny] > babySharkSize) continue;

			dist[nx][ny] = dist[x][y] + 1;

			if (sea[nx][ny] != 0 && sea[nx][ny] < babySharkSize) {
				if (min_dist > dist[nx][ny]) {
					min_x = nx;
					min_y = ny;
					min_dist = dist[nx][ny];
				}
				else if (min_dist == dist[nx][ny]) {
					if (min_x == nx) {
						if (min_y > ny) {
							min_y = ny;
						}
					}
					else if (min_x > nx) {
						min_x = nx;
						min_y = ny;
					}
				}
			}

			q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 9) {
				babyShark = { i,j };
				sea[i][j] = 0;
			}
		}
	}

	while (1) {
		init();
		bfs();

		if (min_x != max_int && min_y != max_int) {
			moveDist += dist[min_x][min_y];
			eatCnt++;
			if (eatCnt == babySharkSize) {
				babySharkSize++;
				eatCnt = 0;
			}
			sea[min_x][min_y] = 0;
			babyShark = { min_x, min_y };
		}
		else {
			break;
		}
	}

	cout << moveDist << "\n";

	return 0;
}