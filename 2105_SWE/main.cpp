 #include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 20 + 1;
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };

int maxDesert = -1;
int N;
int map[MAX][MAX];
bool visited[100 + 1];

void dfs(int x, int y, int dir, int desertCnt, int sx, int sy) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (dir == 3 && nx == sx && ny == sy) {
		maxDesert = max(maxDesert, desertCnt);
		return;
	}

	if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[map[nx][ny]]) {
		visited[map[nx][ny]] = true;
		dfs(nx, ny, dir, desertCnt + 1, sx, sy);
		if (dir < 3)
			dfs(nx, ny, dir + 1, desertCnt + 1, sx, sy);
		visited[map[nx][ny]] = false;
	}


}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		memset(visited, false, sizeof(visited));
		maxDesert = -1;

		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				visited[map[i][j]] = true;
				dfs(i, j, 0, 1, i, j);
				visited[map[i][j]] = false;
			}
		}

		cout << "#" << T << " " << maxDesert << "\n";
	}

	return 0;
}