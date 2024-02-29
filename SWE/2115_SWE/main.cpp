#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int N, M, C, ans, maxPrice;
int map[11][11];
bool visited[11][11];
// cnt-위치 sum-채취한꿀의양<c price-제곱
void getPrice(int x, int y, int cnt, int sum, int price) {
	if (sum > C) return;
	maxPrice = max(maxPrice, price);
	if (cnt == M) return;

	getPrice(x, y + 1, cnt + 1, sum + map[x][y], price + map[x][y] * map[x][y]);
	getPrice(x, y + 1, cnt + 1, sum, price);
}

int getComb(int x, int y) {
	int priceA = 0, priceB = 0;
	
	for (int i = 0; i < M; i++)
		visited[x][y + i] = true;

	maxPrice = 0;
	getPrice(x, y, 0, 0, 0);
	priceA = maxPrice;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			if (!visited[i][j]) {
				maxPrice = 0;
				getPrice(i, j, 0, 0, 0);
				priceB = max(priceB, maxPrice);
			}
		}
	}

	return priceA + priceB;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		memset(visited, false, sizeof(visited));
		ans = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N - M + 1; j++)
				ans = max(ans, getComb(i, j));

		cout << "#" << T << " " << ans << "\n";
	}

	return 0;
}