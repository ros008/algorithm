#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int mapPeple[21][21];
int mapDistrict[21][21];
int visited[21][21];
int people[6];

void divDistrict(int x, int y, int d1, int d2) {
	if (x + d1 + d2 > n || y - d1 < 1 || y + d2 > n) return;
	
	// 5 Áö¿ª±¸ 
	mapDistrict[x][y] = 5;
	for (int i = x, j = y; i <= x + d1; i++, j--)
		mapDistrict[i][j] = 5;


}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mapPeple[i][j];

	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			for (int d1 = 1; d1 <= n; d1++)
				for (int d2 = 1; d2 <= n; d2++)
					divDistrict(x, y, d1, d2);

	return 0;
}