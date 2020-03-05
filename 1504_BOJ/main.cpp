#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 800 + 1;
const int INF = 987654321;

int N, E, ptr1, ptr2;
vector<pair<int, int>> adj[MAX];

vector<int> dijkstra(int src) {
	vector<int> dist(N + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			if (adj[here][i].second == INF) continue;
			int there = adj[here][i].first;
			int nCost = cost + adj[here][i].second;

			if (dist[there] > nCost) {
				dist[there] = nCost;
				pq.push({ nCost, there });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	cin >> ptr1 >> ptr2;

	vector<int> tmp = dijkstra(1);
	int StoOne = tmp[ptr1];
	int StoTwo = tmp[ptr2];
	
	tmp = dijkstra(ptr1);
	int OneToTwo = tmp[ptr2];
	tmp = dijkstra(ptr2);
	int TwoToE = tmp[N];

	tmp = dijkstra(ptr2);
	int TwoToOne = tmp[ptr1];
	tmp = dijkstra(ptr1);
	int OneToE = tmp[N];

	if ((StoOne == INF || OneToTwo == INF || TwoToE == INF)
		&& (StoTwo == INF || TwoToOne == INF || OneToE == INF))
		cout << -1 << "\n";
	else
		cout << min(StoOne + OneToTwo + TwoToE, StoTwo + TwoToOne + OneToE) << "\n";

	return 0;
}