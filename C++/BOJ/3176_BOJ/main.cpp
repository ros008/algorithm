#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000
#define INF 987654321

using namespace std;

int n;
vector<vector<pair<int, int>>> adj;
int depth[MAX + 1];
bool visited[MAX + 1];
int parent[MAX + 1][18];
int minWay[MAX + 1][18];
int maxWay[MAX + 1][18];

void dfs(int cur, int d) {
	visited[cur] = true;
	depth[cur] = d;
	for (int i = 0; i < adj[cur].size(); i++) {
		if (!visited[adj[cur][i].first]) {
			dfs(adj[cur][i].first, d + 1);
			parent[adj[cur][i].first][0] = cur;
			minWay[adj[cur][i].first][0] = adj[cur][i].second;
			maxWay[adj[cur][i].first][0] = adj[cur][i].second;
		}
	}
}

pair<int, int> lca(int a, int b) {
	int mmin = INF;
	int mmax = -INF;
	
	if (depth[a] > depth[b])
		swap(a, b);

	for (int i = 17; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i)) {
			mmin = min(mmin, minWay[b][i]);
			mmax = max(mmax, maxWay[b][i]);
			b = parent[b][i];
		}
	}
	if (a == b) return { mmin, mmax };

	for (int i = 17; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			mmin = min(mmin, min(minWay[b][i], minWay[a][i]));
			mmax = max(mmax, max(maxWay[b][i], maxWay[a][i]));
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	mmin = min(mmin, min(minWay[b][0], minWay[a][0]));
	mmax = max(mmax, max(maxWay[b][0], maxWay[a][0]));

	return { mmin, mmax };
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int a, b, c, d, e, k;

	cin >> n;
	adj.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	dfs(1, 0);

	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
			minWay[i][j] = min(minWay[i][j - 1], minWay[parent[i][j - 1]][j - 1]);
			maxWay[i][j] = max(maxWay[i][j - 1], maxWay[parent[i][j - 1]][j - 1]);
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> d >> e;
		pair<int, int> p = lca(d, e);
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
} 