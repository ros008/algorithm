#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX = 1000 + 1;

int N, M, X;
vector<pair<int, int>> adj[MAX]; // [i] 번째 마을과 first의 거리는 second
int ans = 0;

vector<int> dijkstra(int src) {
	vector<int> dist(N + 1, INF);
	dist[src] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextCost = cost + adj[here][i].second;

			if (dist[there] > nextCost) {
				dist[there] = nextCost;
				pq.push({ nextCost, there });
			}
		}
	}
	return dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		adj[x].push_back({ y,t });
	}

	for (int k = 1; k <= N; k++) {
		vector<int> forDir = dijkstra(k);
		vector<int> revDir = dijkstra(X);

		ans = max(ans, forDir[X] + revDir[k]);
 	}

	cout << ans << "\n";

	return 0;
}

