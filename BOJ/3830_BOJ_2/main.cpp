#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 100000 + 1;

int n, m;
ll parent[MAX], height[MAX], dist[MAX];

ll Find(int x) {
	if (x == parent[x]) return x;
	else {
		ll root = Find(parent[x]);
		dist[x] += dist[parent[x]];
		return parent[x] = root;
	}
}

void Merge(int a, int b, int diff) {
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB) return;

	ll distAB = dist[b] - dist[a] - diff;
	if (height[rootA] >= height[rootB]) {
		dist[rootB] = dist[a] - dist[b] + diff;
		parent[rootB] = rootA;
	}
	else {
		dist[rootA] = dist[b] - dist[a] + diff;
		parent[rootA] = rootB;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i <= n; i++) {
			parent[i] = i; 
			dist[i] = 0;
			height[i] = 1;
		}
		for (int i = 0; i < m; i++) {
			char q;
			cin >> q;
			if (q == '!') {
				int a, b, w;
				cin >> a >> b >> w;
				Merge(a, b, w);
			}
			else if (q == '?') {
				int a, b;
				cin >> a >> b;
				if (Find(a) == Find(b))
					cout << dist[b] - dist[a] << "\n";
				else
					cout << "UNKNOWN" << "\n";
			}
		}
	}

	return 0;
}