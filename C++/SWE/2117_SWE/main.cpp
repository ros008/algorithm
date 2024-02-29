#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 20 + 2;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int N, M, ans;
int map[MAX][MAX];
int price[MAX];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	bool visited[MAX][MAX];
	int depth = 1;
	int houseCnt = map[a][b];

	memset(visited, false, sizeof(visited));
	q.push({ a,b });
	visited[a][b] = true;

	while (!q.empty()) {
		int qSize = q.size();

		if (houseCnt*M >= price[depth]) 
			ans = max(ans, houseCnt);
		
		if (depth > N) return;

		while (qSize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
				
				q.push({ nx, ny });
				visited[nx][ny] = true;
				if (map[nx][ny] == 1)
					houseCnt++;
			}
		}
		depth++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int i = 1; i <= 21; i++)
		price[i] = i * i + (i - 1)*(i - 1);
	for (int T = 1; T <= tc; T++) {
		ans = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				bfs(i, j);

		cout << "#" << T << " " << ans << "\n";
	}

	return 0;
}