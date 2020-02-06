#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, l;
int map[501][501];
int ans = 0;
bool isBridge[501];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	// 가로
	for (int i = 0; i < n; i++) {
		bool isRoad = true;
		memset(isBridge, false, sizeof(isBridge));
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				continue;
			}
			else if (map[i][j] + 1 == map[i][j + 1]) {
				int k = 1;
				if (isBridge[j]) {
					isRoad = false;
					break;
				}
				while (j - k >= 0 && map[i][j] == map[i][j - k] && !isBridge[j - k]) k++;
				if (k < l) {
					isRoad = false;
					break;
				}
				for (int a = 0; a < l; a++) isBridge[j - a] = true;
				continue;
			}
			else if (map[i][j] == map[i][j + 1] + 1) {
				int k = 1;
				if (isBridge[j + 1]) {
					isRoad = false;
					break;
				}	
				while (j + k + 1 < n && map[i][j + 1] == map[i][j + k + 1] && !isBridge[j + k + 1]) k++;
				if (k < l) {
					isRoad = false;
					break;
				}
				for (int a = 1; a <= l; a++) isBridge[j + a] = true;
				continue;
			}
			else {
				isRoad = false;
				break;
			}
		}

		if (isRoad) ans++;
	}

	// 세로
	for (int j = 0; j < n; j++) {
		bool isRoad = true;
		memset(isBridge, false, sizeof(isBridge));
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				continue;
			}
			else if (map[i][j] + 1 == map[i + 1][j]) {
				int k = 1;
				if (isBridge[i]) {
					isRoad = false;
					break;
				}				
				while (i - k >= 0 && map[i][j] == map[i - k][j] && !isBridge[i - k]) k++;
				if (k < l) {
					isRoad = false;
					break;
				}
				for (int a = 0; a < l; a++) isBridge[i - a] = true;
				continue;
			}
			else if (map[i][j] == map[i + 1][j] + 1) {
				int k = 1;
				if (isBridge[i + 1]) {
					isRoad = false;
					break;
				}				
				while (i + k + 1  < n && map[i + 1][j] == map[i + k + 1][j] && !isBridge[i + k + 1]) k++;
				if (k < l) {
					isRoad = false;
					break;
				}
				for (int a = 1; a <= l; a++) isBridge[i + a] = true;
				continue;
			}
			else {
				isRoad = false;
				break;
			}

		}

		if (isRoad) ans++;
	}

	cout << ans << "\n";

	return 0;
}