#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;;
int map[101];
bool visited[101];
int dist[101];
queue<int> q;

void bfs() {
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int nextLoc = cur + i;
			if (nextLoc > 100) continue;
			if (map[nextLoc] > 0) nextLoc = map[nextLoc];
			if (!visited[nextLoc]) {
				visited[nextLoc] = true;
				q.push(nextLoc);
				dist[nextLoc] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> x >> y;
		map[x] = y;
	}
	
	bfs();
	cout << dist[100] << "\n";

	return 0;
}