#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 20000 + 1;

int N;
int parent[MAX];
int len[MAX];

int Find(int x) {
	if (x == parent[x]) return x;
	else {
		int ret = Find(parent[x]);
		len[x] += len[parent[x]];
		return parent[x] = ret;
	}
}

void Merge(int x, int y) {
	parent[x] = y;
	len[x] = abs(x - y) % 1000;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			len[i] = 0;
		}
			
		while (1) {
			char q;
			int a, b;
			cin >> q;

			if (q == 'O')
				break;
			else if (q == 'E') {
				cin >> a;
				Find(a);
				cout << len[a] << "\n";
			}
			else if (q == 'I') {
				cin >> a >> b;
				Merge(a, b);
			} 
		}
	}

	return 0;
}