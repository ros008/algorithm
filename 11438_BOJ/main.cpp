#include <iostream>
#include <vector>

using namespace std;
int depth[100001];
int visited[100001];
int parent[100001][18];
vector<int> adj[100001];
int n, m;
int a, b;

void dfs(int cur, int d) {
	// 깊이 구해놓기 
	visited[cur] = true;
	depth[cur] = d;
	for (int i = 0; i < adj[cur].size(); i++) {
		if (!visited[adj[cur][i]]) {
			parent[adj[cur][i]][0] = cur; // 바로 위 부모 설정
			dfs(adj[cur][i], d + 1);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b])
		swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i))
			b = parent[b][i];
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {	
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);
	
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}

	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}