#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int maxLen = 0;
int N, K;
int map[10][10];
int curMaxHeight = 0;
bool visited[10][10];

void dfs(int x, int y, int curHeight, bool isConstruct, int curLen) {

	maxLen = max(maxLen, curLen);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (visited[nx][ny]) continue;

		if (map[nx][ny] < curHeight) {
			visited[nx][ny] = true;
			dfs(nx, ny, map[nx][ny], isConstruct, curLen + 1);
			visited[nx][ny] = false;
		}
		else {
			if (!isConstruct && map[nx][ny] - K < curHeight) {
				visited[nx][ny] = true;
				dfs(nx, ny, curHeight - 1, 1, curLen + 1);
				visited[nx][ny] = false;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		maxLen = 0;
		curMaxHeight = 0;

		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				curMaxHeight = max(curMaxHeight, map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == curMaxHeight) {
					visited[i][j] = true;
					dfs(i, j, map[i][j], 0, 1); //  x, y, 현재높이, 공사 여부, 현재 길이
					visited[i][j] = false;
				}
			}
		}

		cout << "#" << T << " " << maxLen << "\n";
	}

	return 0;
}