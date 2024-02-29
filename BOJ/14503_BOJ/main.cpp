#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 51

using namespace std;

// 合 悼 巢 辑
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int ans = 0;
int n, m, r, c, d; // 0合 1悼 2巢 3辑
int map[MAX][MAX];
// 后 0 
// 寒 1
// 没家 2

void getInput() {
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void cleanRoom() {
	while (1) {
		if (map[r][c] == 0) {
			map[r][c] = 2;
			ans++;
		}

		bool found = false;
		
		for (int i = 0; i < 4; i++) {
			int nextDir = (d + 3 - i) % 4;
			int nextR = r + dr[nextDir];
			int nextC = c + dc[nextDir];

			if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m) {
				if (map[nextR][nextC] == 0) {
					r = nextR;
					c = nextC;
					d = nextDir;
					found = true;
					break;
				}
			}
		}

		if (!found) {
			int backR = r - dr[d];
			int backC = c - dc[d];
			if ((backR >= 0 && backR < n && backC >= 0 && backC < m) && (map[backR][backC] != 1)) {
				r = backR;
				c = backC;
			}
			else {
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	getInput();
	cleanRoom();
	cout << ans << "\n";

	return 0;
}