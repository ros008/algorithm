#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 500 + 1;
const int INF = 987654321;

int n, m;
int dist[MAX][MAX];
int cnt[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; // a<b
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF) {
				cnt[i]++; cnt[j]++;
				if (cnt[i] == n - 1) ans++;
				if (cnt[j] == n - 1) ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}