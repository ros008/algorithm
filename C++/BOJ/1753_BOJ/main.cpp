#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 8765432
#define MAX 20000
using namespace std;

vector<pair<int, int>> adj[MAX + 1];
int dist[MAX + 1];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e, start;
	int a, b, len;
	
	cin >> v >> e;
	cin >> start;

	for (int i = 0; i <= v; i++) dist[i] = INF;
	dist[start] = 0;
	
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> len;
		adj[a].push_back(make_pair(b, len));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		if (cur_dist > dist[cur]) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int next_dist = cur_dist + adj[cur][i].second;
			if (next_dist < dist[next]) {
				dist[next] = next_dist;
				pq.push(make_pair(next_dist, next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}