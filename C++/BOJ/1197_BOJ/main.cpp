#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 10000 + 1;

int V, E;
vector<pair<int, int>> adj[MAX];
vector<pair<int, pair<int, int>>> edges;
vector<int> parent(MAX);

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB) return;

	if (rootA < rootB) parent[rootB] = rootA;
	else parent[rootA] = rootB;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ B,C });
		adj[B].push_back({ A,C });
	}
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 1; i <= V; i++) 
		for (int j = 0; j < adj[i].size(); j++) 
			edges.push_back({ adj[i][j].second,{i, adj[i][j].first} });
	
	sort(edges.begin(), edges.end());
	int cost = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (Find(edges[i].second.first) == Find(edges[i].second.second))
			continue;
		Merge(edges[i].second.first, edges[i].second.second);
		cost += edges[i].first;
	}

	cout << cost << "\n";

	return 0;
}