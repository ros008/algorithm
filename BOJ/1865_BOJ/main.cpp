#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 500 + 1;
const int INF = 987654321;



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int TC;
	cin >> TC;

	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;

		vector<pair<int, int>> adj[MAX];
		vector<int> dist(MAX, INF);		
		dist[1] = 0;

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			adj[S].push_back({ E,T });
			adj[E].push_back({ S,T });
		}
		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			adj[S].push_back({ E,(-1)*T });
		}

		bool has_cycle = false;
		for (int idx = 1; idx <= N; idx++) {
			for (int here = 1; here <= N; here++) {
				for (int i = 0; i < adj[here].size(); i++) {
					int there = adj[here][i].first;
					int cost = adj[here][i].second;
					if (dist[there] > dist[here] + cost) {
						dist[there] = dist[here] + cost;
						if (idx == N) has_cycle = true;
					}
				}
			}
		}

		if (has_cycle)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}