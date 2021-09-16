#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 500 + 1;
const int INF = 987654321;

int N, M;
vector<pair<int, int>> adj[MAX];

vector<int> bellmanFord(int src) {
	vector<int> dist(N + 1, INF);
	dist[src] = 0;
	bool updated = false;

	for (int k = 1; k <= N; k++) {
		for (int here = 1; here <= N; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (dist[here] != INF && dist[there] > dist[here] + cost) {
					dist[there] = dist[here] + cost;
					if (k == N) updated = true;
				}
			}
		}
	}

	if (updated) 
		dist.clear();
	return dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ B,C });
	}

	vector<int> ans = bellmanFord(1);
	
	if (ans.size() == 0) 
		cout << -1 << "\n";
	else {
		for (int i = 2; i <= N; i++)
			if (ans[i] == INF)
				cout << -1 << "\n";
			else
				cout << ans[i] << "\n";
	}

	return 0;
}