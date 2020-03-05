#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;

int n, m;
int dist[MAX][MAX];

void floyd() {

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";
		cout << "\n";
	}

	return 0;
}