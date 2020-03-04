#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 125 + 1;
const int INF = 987654321;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

bool visited[MAX][MAX];
int dist[MAX][MAX];
int graph[MAX][MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 0;
	while (1) {
		int N;

		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = INF;
		memset(visited, false, sizeof(visited));
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> graph[i][j];

		// °Å¸®, x, y
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ 0, {0,0} });
		visited[0][0] = true;

		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int curDist = pq.top().first;
			pq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					int nDist = curDist + graph[nx][ny];
					if (!visited[nx][ny] && nDist < dist[nx][ny]) {
						dist[nx][ny] = nDist;
						pq.push({ nDist,{nx,ny} });
						visited[nx][ny] = true;
					}
				}
			}
		}
		
		cout << "Problem " << ++T << ": " << dist[N - 1][N - 1] + graph[0][0] << "\n";
	}

	return 0;
}

