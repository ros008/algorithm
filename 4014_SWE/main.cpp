#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int N, X, cnt;
int map[21][21];

void findSlope() {
	bool visited[21][21];
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] + 1 == map[i][j + 1]) {
				for (int k = 0; k < X; k++) {
					if (j - k < 0 || map[i][j] != map[i][j - k] || visited[i][j - k]) {
						flag = false;
						break;
					}
				}
				if(flag)
					for (int k = 0; k < X; k++)
						visited[i][j - k] = true;
			}
			else if (map[i][j] == map[i][j + 1] + 1) {
				for (int k = 0; k < X; k++) {
					if (j + 1 + k >= N || map[i][j + 1] != map[i][j + 1 + k] || visited[i][j + 1 + k]) {
						flag = false;
						break;
					}
				}
				if (flag)
					for (int k = 0; k < X; k++)
						visited[i][j + 1 + k] = true;
			}
			else if (map[i][j] == map[i][j + 1]) {
				continue;
			}
			else {
				flag = false;
				break;
			}
			if (!flag) break;
		}
		if (flag) cnt++;
	}
	
	memset(visited, false, sizeof(visited));
	for (int j = 0; j < N; j++) {
		bool flag = true;
		for (int i = 0; i < N - 1; i++) {
			if (map[i][j] + 1 == map[i + 1][j]) {
				for (int k = 0; k < X; k++) {
					if (i - k < 0 || map[i][j] != map[i - k][j] || visited[i - k][j]) {
						flag = false;
						break;
					}
				}
				if (flag)
					for (int k = 0; k < X; k++)
						visited[i - k][j] = true;
			}
			else if (map[i][j] == map[i + 1][j] + 1) {
				for (int k = 0; k < X; k++) {
					if (i + 1 + k >= N || map[i + 1][j] != map[i + 1 + k][j] || visited[i + 1 + k][j]) {
						flag = false;
						break;
					}
				}
				if (flag)
					for (int k = 0; k < X; k++)
						visited[i + 1 + k][j] = true;
			}
			else if (map[i][j] == map[i + 1][j]) {
				continue;
			}
			else {
				flag = false;
				break;
			}
			if (!flag) break;
		}
		if (flag) cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cnt = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		findSlope();

		cout << "#" << T << " " << cnt << "\n";
	}

	return 0;
}