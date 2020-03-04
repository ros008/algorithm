#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int N, M;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dist[i][j] = INF;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	dist[1][1] = 0;
	pq.push({ 0, {1,1} });
	visited[1][1] = true;

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int curDist = pq.top().first;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				int nDist = (map[nx][ny] == '1') ? curDist + 1 : curDist;
				if (!visited[nx][ny] && nDist < dist[nx][ny]) {
					dist[nx][ny] = nDist;
					pq.push({ nDist, {nx, ny} });
					visited[nx][ny] = true;
				}
			}
		}
	}

	cout << dist[N][M] << "\n";

	return 0;
}