#include <iostream>
#include <vector>

#define MAX 100000
using namespace std;

typedef long long ll;

int n, m;
ll dist[MAX + 1];
ll parent[MAX + 1];
ll root_size[MAX + 1];

ll _find(ll a) {
	if (parent[a] == a) return a;
	else {
		ll root = _find(parent[a]);
		dist[a] += dist[parent[a]];
		return parent[a] = root;
	}
}

void _union(ll a, ll b, ll k) {
	ll rootA = _find(a);
	ll rootB = _find(b);
	ll new_dist = dist[b] - dist[a] - k;
	if (rootA != rootB) {
		if (root_size[rootA] >= root_size[rootB]) {
			parent[rootA] = rootB;
			dist[rootA] += new_dist;
			root_size[rootB] += root_size[rootA];
			root_size[rootA] = 1;
		}
		else {
			parent[rootB] = rootA;
			dist[rootB] -= new_dist;
			root_size[rootA] += root_size[rootB];
			root_size[rootB] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		ll n, m;
		cin >> n >> m;
		if (n == 0 & m == 0) break;

		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			dist[i] = 0;
			root_size[i] = 1;
		}
		for (ll i = 0; i < m; i++) {
			char q;
			cin >> q;
			if (q == '!') {
				ll a, b, w;
				cin >> a >> b >> w;
				_union(a, b, w);
			}
			else if (q == '?') {
				ll a, b;
				cin >> a >> b;
				if (_find(a) == _find(b)) {
					cout << dist[b] - dist[a] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}

	return 0;
}