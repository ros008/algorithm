#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
bool visited[3001];
bool isCycle[3001];
int dist[3001];
bool cycle;
vector<int> station[3001];

void dfs(int start, int cur, int cnt) {

	visited[cur] = true;
	for (int i = 0; i < station[cur].size(); i++) {
		int next = station[cur][i];
		if (!visited[next]) {
			dfs(start, next, cnt + 1);
		}
		else {
			if (next == start && cnt >= 2) {
				cycle = true;
				return;
			}
		}
	}
}

void bfs() {
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= n; i++) {
		if (isCycle[i]) {
			dist[i] = 0;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < station[cur].size(); i++) {
			if (dist[station[cur][i]] == -1) {
				q.push(station[cur][i]);
				dist[station[cur][i]] = dist[cur] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		station[a].push_back(b);
		station[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		cycle = false;
		dfs(i, i, 0);
		if (cycle) {
			isCycle[i] = true;
		}
	}

	bfs();

	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";

	return 0;
}