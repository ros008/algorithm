#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1000 + 1;
const int INF = 987654321;

int v, e, n, m;
vector<pair<int, int>> adj[MAX];

vector<int> fireStation;
vector<int> fire;
vector<int> dist;

vector<int> dijkstra(int src) {
	dist[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, src });

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nCost = cost + adj[here][i].second;

			if (dist[there] >= nCost) {
				dist[there] = nCost;
				pq.push({ nCost, there });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		cin >> v >> e >> n >> m;
		dist = vector<int>(v + 1, INF);
		memset(adj, 0, sizeof(adj));
		fireStation.clear();
		fire.clear();
		for (int i = 0; i < e; i++) {
			int a, b, t;
			cin >> a >> b >> t;
			adj[a].push_back({ b,t });
			adj[b].push_back({ a,t });
		}
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			fire.push_back(input);
		}
		for (int i = 0; i < m; i++) {
			int input;
			cin >> input;
			fireStation.push_back(input);
			adj[0].push_back({ input, 0 });
			dist[input] = 0;
		}

		vector<int> ans = dijkstra(0);
		int total = 0;
		for (int i = 0; i < fire.size(); i++) {
			total += ans[fire[i]];
		}
		cout << total << "\n";
	}

	return 0;
}