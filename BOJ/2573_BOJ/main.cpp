#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 300 + 1;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m;
int map[MAX][MAX];
int tmpMap[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;

void globalWarming() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmpMap[i][j] = map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (tmpMap[nx][ny] > 0) {
							tmpMap[nx][ny] -= 1;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = tmpMap[i][j];
}

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

			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] > 0 && !visited[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
}

int meltCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i];
		if (map[nx][ny] == 0) cnt++;
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	while (1) {
		int section = 0;
		memset(visited, false, sizeof(visited));
		memset(tmpMap, 0, sizeof(tmpMap));
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0 && !visited[i][j]) {
					section++;
					bfs(i, j);
				}
			}
		}
		
		if (section >= 2) {
			cout << ans << "\n";
			break;
		}
		if (section == 0) {
			cout << 0 << "\n";
			break;
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0) {
					tmpMap[i][j] = map[i][j] - meltCnt(i, j);
					if (tmpMap[i][j] < 0) tmpMap[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j] = tmpMap[i][j];

		ans++;
	}

	return 0;
}