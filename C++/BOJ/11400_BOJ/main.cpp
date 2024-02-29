#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

int visited[MAX + 1];
vector<int> adj[MAX + 1];
vector<pair<int, int>> isCut;
int d = 0;

int dfs(int cur, int parent) {
	visited[cur] = ++d;
	int ret = visited[cur];

	for (int i = 0; i < adj[cur].size(); i++) {
		int next = adj[cur][i];
		if (next == parent)
			continue;

		if (visited[adj[cur][i]]) {
			ret = min(ret, visited[adj[cur][i]]);
		}
		else {
			int prev = dfs(next, cur);
			if (prev > visited[cur])
				isCut.push_back({ min(cur, next), max(cur, next) });
			ret = min(ret, prev);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e;
	int a, b;

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= v; i++)
		if (!visited[i])
			dfs(i, 0);
	
	sort(isCut.begin(), isCut.end());

	cout << isCut.size() << "\n";

	for (int i = 0; i < isCut.size(); i++) 
		cout << isCut[i].first << " " << isCut[i].second << "\n";

	return 0;
}