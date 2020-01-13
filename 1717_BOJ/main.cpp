#include <iostream>

using namespace std;

const int MAX = 1000000;
				
int root[MAX + 1];
int depth[MAX + 1];
int n, m;

void init() {
	for (int i = 0; i <= n; i++) 
		root[i] = i;
}

int _find(int x) {
	if (root[x] == x)
		return x;
	else
		return root[x] = _find(root[x]);
}

void _union(int a, int b) {
	int x = _find(a);
	int y = _find(b);

	if (depth[x] > depth[y]) {
		root[y] = x;
	}
	else {
		root[x] = y;
		if (depth[x] == depth[y])
			depth[y]++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	init();

	while (m--) {
		int k, a, b;
		cin >> k >> a >> b;

		if (k == 1) {
			if (_find(a) == _find(b))
				cout << "YES\n";
			else
				cout << "NO\n";	
		}
		else if (k == 0) {
			_union(a, b);
		}
	}

	return 0;
}