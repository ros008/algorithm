#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

const int dx[] = { -2,-2,0,0,2,2 };
const int dy[] = { -1,1,-2,2,-1,1 };

int n;
int r1, c1, r2, c2;
bool visited[201][201];

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r1,c1},0 });
	visited[r1][c1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == r2 && y == c2) {
			cout << cnt << "\n";
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push({ {nx,ny},cnt + 1 });
		}
	}

	cout << -1 << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	bfs();

	return 0;
}