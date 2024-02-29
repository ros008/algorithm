#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 51
#define INF 1000000007

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int r, c;
char forestMap[MAX][MAX];
int waterMap[MAX][MAX];
bool visited[MAX][MAX];

queue<pair<int, int>> waterQ;
pair<int, int> start;
pair<int, int> dest;

int BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ start, 0 });
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curTime = q.front().second;
		q.pop();

		if (x == dest.first && y == dest.second)
			return curTime;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (visited[nx][ny] == false && forestMap[nx][ny] != 'X' && waterMap[nx][ny] > curTime + 1) {
					visited[nx][ny] = true;
					q.push({ {nx,ny},curTime + 1 });
				}
			}
		}
	}

	return -1;
}

void makeWaterMap() {
	while (!waterQ.empty()) {
		int x = waterQ.front().first;
		int y = waterQ.front().second;
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < r&&ny >= 0 && ny < c) {
				if (forestMap[nx][ny] == '.') {
					if (waterMap[nx][ny] > waterMap[x][y] + 1) {
						waterMap[nx][ny] = waterMap[x][y] + 1;
						waterQ.push({ nx, ny });
					}
				}
			}
		}
	}
}

void getInput() {
	memset(waterMap, INF, sizeof(waterMap));
	memset(visited, false, sizeof(visited));

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> forestMap[i][j];
			if (forestMap[i][j] == '*') {
				waterMap[i][j] = 0;
				waterQ.push({ i,j });
			}
			else if (forestMap[i][j] == 'S') {
				start = { i,j };
			}
			else if (forestMap[i][j] == 'D') {
				dest = { i,j };
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	getInput();
	makeWaterMap();

	int ans = BFS();
	if (ans < 0)
		cout << "KAKTUS" << "\n";
	else
		cout << ans << "\n";

	return 0;
}