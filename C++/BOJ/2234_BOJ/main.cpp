#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 50

using namespace std;

const int dx[] = { 0,-1,0,1 }; // ¼­1ºÏ2µ¿4³²8
const int dy[] = { -1,0,1,0 };

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];

int bfs(int a, int b) {
	int roomSize = 0;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = true;
	roomSize++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int wall = 1;
		for (int i = 0; i < 4; i++) {
			if ((wall & map[x][y]) != wall) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
					if (!visited[nx][ny]) {
						roomSize++;
						q.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
			wall = wall * 2;
		}
	}

	return roomSize;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int roomCnt = 0;
	int bigRoomSize = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bigRoomSize = max(bigRoomSize, bfs(i, j));
				roomCnt++;
			}
		}
	}

	cout << roomCnt << "\n";
	cout << bigRoomSize << "\n";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int w = 1; w <= 8; w *= 2) {
				if ((map[i][j] & w) == w) {
					memset(visited, false, sizeof(visited));
					map[i][j] = map[i][j] - w;
					bigRoomSize = max(bigRoomSize, bfs(i, j));
					map[i][j] = map[i][j] + w;
				}
			}
		}
	}

	cout << bigRoomSize << "\n";

	return 0;
}