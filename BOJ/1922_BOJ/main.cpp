#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edge;
int root[100001];

int _find(int x) {
	if (root[x] == x) return x;
	return root[x] = _find(root[x]);
}

void _union(int x, int y) {
	int a = _find(x);
	int b = _find(y);
	if (a != b) root[b] = a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); 

	int n, m, ans = 0;
	cin >> n >> m;
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}

	for (int i = 0; i <= 100000; i++)
		root[i] = i;

	sort(edge.begin(), edge.end());

	for (int i = 0; i < m; i++) {
		if (_find(edge[i].second.first) != _find(edge[i].second.second)) {
			_union(edge[i].second.first, edge[i].second.second);
			ans += edge[i].first;
		}
	}

	cout << ans;

	return 0;
}