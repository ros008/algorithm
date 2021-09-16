#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 400 + 1;
const int INF = 987654321;

int n, k, s;
int dist[MAX][MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << dist[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] == INF && dist[b][a] == INF)
			cout << 0 << "\n";
		else if (dist[a][b] != INF)
			cout << -1 << "\n";
		else
			cout << 1 << "\n";
	}

	return 0;
}