#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int city[101][101];
int dist[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	int a, b, c;

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			city[i][j] = (i == j) ? 0 : INF;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (city[i][j] == INF ? 0 : city[i][j]) << " ";
		}
		cout << "\n";
	}

	return 0;
}