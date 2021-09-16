#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

vector<pair<int, int>> adj[501];
int dist[501];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int a, b, c;

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}

	bool minusCycle = false;
	for (int k = 0; k < n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				int next = adj[i][j].first;
				int next_dist = adj[i][j].second;
				if (dist[i] != INF && dist[next] > dist[i] + next_dist) {
					dist[next] = dist[i] + next_dist;
					if (k == n - 1) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) {
		cout << "-1\n";
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	
	return 0;
}