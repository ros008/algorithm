#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

vector<pair<int, int>> adj[1001];
priority_queue<int> dist[1001];
// pair: 소요시간, 도착지

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[1].push(0);
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int cur_node = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[cur_node].size(); i++) {
			int next_node = adj[cur_node][i].second;
			int next_dist = adj[cur_node][i].first;

			if (dist[next_node].size() < k) {
				dist[next_node].push(next_dist + cur_dist);
				pq.push({ next_dist + cur_dist, adj[cur_node][i].second });
			}
			else if (dist[next_node].top() > next_dist + cur_dist) {
				dist[next_node].pop();
				dist[next_node].push(next_dist + cur_dist);
				pq.push({ next_dist + cur_dist, adj[cur_node][i].second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k; // n: 도시 m: 도로 k: k번째 최단경로

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}
	
	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() == k)
			cout << dist[i].top() << "\n";
		else
			cout << -1 << "\n";
	}

	return 0;
}