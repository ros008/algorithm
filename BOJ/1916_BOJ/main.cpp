#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000 + 1;
const int INF = 987654321;

int N, M;
int startPos, endPos;
vector<pair<int, int>> adj[MAX];

vector<int> dijkstra(int src) {

	vector<int> dist(N + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, startPos });

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
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

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		adj[x].push_back({ y,c });
	}
	cin >> startPos >> endPos;

	vector<int> result = dijkstra(startPos);

	cout << result[endPos] << "\n";

	return 0;
}