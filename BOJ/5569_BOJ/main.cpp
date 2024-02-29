#include <iostream>

using namespace std;

#define MOD 100000

int way[101][101][4] = { 0, }; // 오른 0, 아래 1, 오른아래 2, 아래오른 3

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int w, h;
	cin >> w >> h;
	//h,w
	for (int i = 1; i <= w; i++) 
		way[1][i][0] = 1;
	
	for (int i = 0; i <= h; i++)
		way[i][1][1] = 1;

	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			way[i][j][0] = (way[i][j - 1][3] + way[i][j - 1][0]) % MOD;
			way[i][j][1] = (way[i - 1][j][1] + way[i - 1][j][2]) % MOD;
			way[i][j][2] = (way[i - 1][j][0]) % MOD;
			way[i][j][3] = (way[i][j - 1][1]) % MOD;
		}
	}

	int result = (way[h][w][0] + way[h][w][1] + way[h][w][2] + way[h][w][3]) % MOD;

	cout << result << "\n";

	return 0;
}