#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 2000 + 1;
const int INF = 987654321;

int n, m, t, s, g, h, distGH;
vector<pair<int, int>> adj[MAX];
vector<int> dest;

vector<int> dijkstra(int src) {
	vector<int> dist(n + 1, INF);
	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		if (dist[cur] < curDist) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int nextD = adj[cur][i].first;
			int nDist = curDist + adj[cur][i].second;

			if (dist[nextD] > nDist) {
				dist[nextD] = nDist;
				pq.push({ nDist, nextD });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i <= n; i++) adj[i].clear();
		dest.clear();
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back({ b,d });
			adj[b].push_back({ a,d });
			if ((a == g && b == h) || (a == h && b == g))
				distGH = d;
		}
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			dest.push_back(x);
		}

		vector<int> fromS = dijkstra(s);
		vector<int> GtoDest = dijkstra(g);
		vector<int> HtoDest = dijkstra(h);

		sort(dest.begin(), dest.end());
		for (int i = 0; i < dest.size(); i++) {
			int cur = dest[i];
			if (fromS[cur] == fromS[g] + distGH + HtoDest[cur]) cout << cur << " ";
			else if (fromS[cur] == fromS[h] + distGH + GtoDest[cur]) cout << cur << " ";
		}
		cout << "\n";
	}

	return 0;
}