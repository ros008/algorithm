#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ºÏ µ¿ ³² ¼­
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int n, m;
int ans = 0;
int officeMap[9][9];
vector<pair<int, int>> cc;
vector<int> dir;

void checkSpace() {
	int cnt = 0;
	int newMap[9][9];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			newMap[i][j] = officeMap[i][j];

	for (int i = 0; i < cc.size(); i++) {
		int x = cc[i].first;
		int y = cc[i].second;
		int d = dir[i];
		int cctvType = officeMap[x][y];
		int nx, ny, nd;

		nx = x + dx[d];
		ny = y + dy[d];
		while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (newMap[nx][ny] == 6)
				break;
			if (newMap[nx][ny] == 0)
				newMap[nx][ny] = -1;
			nx = nx + dx[d];
			ny = ny + dy[d];
		}

		if (cctvType == 2 || cctvType == 4 || cctvType == 5) {
			nd = (d + 2) % 4;
			nx = x + dx[nd];
			ny = y + dy[nd];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (newMap[nx][ny] == 6)
					break;
				if (newMap[nx][ny] == 0)
					newMap[nx][ny] = -1;
				nx = nx + dx[nd];
				ny = ny + dy[nd];
			}
		}

		if (cctvType == 3 || cctvType == 4 || cctvType == 5) {
			nd = (d + 1) % 4;
			nx = x + dx[nd];
			ny = y + dy[nd];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (newMap[nx][ny] == 6)
					break;
				if (newMap[nx][ny] == 0)
					newMap[nx][ny] = -1;
				nx = nx + dx[nd];
				ny = ny + dy[nd];
			}
		}

		if (cctvType == 5) {
			nd = (d + 3) % 4;
			nx = x + dx[nd];
			ny = y + dy[nd];
			while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (newMap[nx][ny] == 6)
					break;
				if (newMap[nx][ny] == 0)
					newMap[nx][ny] = -1;
				nx = nx + dx[nd];
				ny = ny + dy[nd];
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (newMap[i][j] == 0)
				cnt++;

	ans = min(ans, cnt);
}

void bfs(int idx) {
	if (idx == cc.size()) {
		checkSpace();
		return;
	}

	int x = cc[idx].first;
	int y = cc[idx].second;
	int cctvNum = officeMap[x][y];

	if (cctvNum >= 1 && cctvNum <= 4) {
		for (int i = 0; i < 4; i++) {
			dir[idx] = (dir[idx] + 1) % 4;
			bfs(idx + 1);
		}
	}
	else if (cctvNum == 5) {
		bfs(idx + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> officeMap[i][j];
			if (officeMap[i][j] > 0 && officeMap[i][j] < 6) {
				cc.push_back({ i,j });
				dir.push_back(0);
			}
			if (officeMap[i][j] == 0)
				ans++;
		}
	}
		
	bfs(0);
	cout << ans << "\n";

	return 0;
}