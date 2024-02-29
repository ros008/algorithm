#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>

#define INF 987654321

using namespace std;

int n, m, start, dest;
vector<pair<int, int>> adj[10000 + 1];
vector<pair<int, int>> adj_rev[10000 + 1];
int dist[500 + 1];

// pair = ( 거리, 노드 );

void dijkstra() {

	for (int i = 0; i < n; i++) dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur_node = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		
		if (cur_dist > dist[cur_node]) continue;
		
		for (int i = 0; i < adj[cur_node].size(); i++) {
			int next = adj[cur_node][i].second;
			int next_dist = dist[cur_node] + adj[cur_node][i].first;
			//int next_dist = cur_dist + adj[cur_node][i].first;

			if (adj[cur_node][i].first == -1) 
				continue;
			
			if (next_dist < dist[next]) {
				dist[next] = next_dist;
				pq.push({ next_dist, next });
				
				adj_rev[next].clear();
				adj_rev[next].push_back({ next_dist, cur_node });
			}
			else if (next_dist == dist[next]) {
				adj_rev[next].push_back({ next_dist, cur_node });
			}
		}
	}
}

void deletePath() {
	queue<int> q;
	q.push(dest);
	
	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();
	
		for (int i = 0; i < adj_rev[cur_node].size(); i++) {
			int next = adj_rev[cur_node][i].second;
			
			for (int j = 0; j < adj[next].size(); j++) {
				if (adj[next][j].second == cur_node)
					adj[next][j].first = -1;
			}
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {

		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> start >> dest;

		memset(adj, 0, sizeof(adj));
		memset(adj_rev, 0, sizeof(adj_rev));

		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			adj[u].push_back({ p, v }); // { 거리, 연결된 정점 }
		}
		
		dijkstra();

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < adj_rev[i].size(); j++) {
		//		cout << i << " " << adj_rev[i][j].second;
		//	}
		//	cout << "\n";
		//}

		deletePath();
		dijkstra();

		if (dist[dest] == INF) 
			cout << "-1\n";
		else
			cout << dist[dest] << "\n";
	}
	
	return 0;
}