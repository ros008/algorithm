#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N_MAX = 200 + 1;
const int M_MAX = 1000 + 1;

int N, M;
int parent[N_MAX];
int path[M_MAX];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int connect;
			cin >> connect;
			if (connect == 1) Merge(i, j);
		}
	}

	for (int i = 1; i <= M; i++)
		cin >> path[i];

	bool ans = true;
	for (int i = 1; i < M; i++) {
		if (Find(path[i]) != Find(path[i + 1])) {
			ans = false;
			break;
		}
	}

	if (ans) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}