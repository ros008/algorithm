#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define INF 1000000007
#define MAX 1001

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int w, h;
char buildingMap[MAX][MAX];
int fireMap[MAX][MAX];
bool visited[MAX][MAX];

queue<pair<int, int>> fireQ;
pair<int, int> startPos;

int BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ startPos, 0 });
	visited[startPos.first][startPos.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int curTime = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				return curTime + 1;

			if (!visited[nx][ny] && buildingMap[nx][ny] != '#' && fireMap[nx][ny] > curTime + 1) {
				visited[nx][ny] = true;
				q.push({ {nx,ny}, curTime + 1 });
			}
		}
	}

	return -1;
}

void makeFireMap() {
	while (!fireQ.empty()) {
		int x = fireQ.front().first;
		int y = fireQ.front().second;
		fireQ.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (buildingMap[nx][ny] == '.') {
					if (fireMap[nx][ny] > fireMap[x][y] + 1) {
						fireMap[nx][ny] = fireMap[x][y] + 1;
						fireQ.push({ nx, ny });
					}
				}
			}
		}
	}
}

void getInput() {
	memset(fireMap, INF, sizeof(fireMap));
	memset(visited, false, sizeof(visited));

	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> buildingMap[i][j];
			if (buildingMap[i][j] == '*') {
				fireMap[i][j] = 0;
				fireQ.push({ i,j });
			}
			else if (buildingMap[i][j] == '@') {
				startPos = { i,j };
				buildingMap[i][j] = '.';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		getInput();
		makeFireMap();

		int ans = BFS();
		if (ans < 0)
			cout << "IMPOSSIBLE" << "\n";
		else {
			cout << ans << "\n";
		}
	}

	return 0;
}