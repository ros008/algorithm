#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int n, m, h;
bool visited[11][31];
int ans = INF;

bool findItoI() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			if (visited[cur][j] == true)
				cur = cur + 1;
			else if (visited[cur - 1][j] == true)
				cur = cur - 1;
		}
		if (cur != i) return false;
	}
	return true;
}

void selectLine(int idx, int cnt) {
	if (cnt > 3) return;
	;
	if (findItoI()) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = idx; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (visited[j][i]) continue;
			if (visited[j - 1][i]) continue;
			if (visited[j + 1][i]) continue;

			visited[j][i] = true;
			selectLine(i, cnt + 1);
			visited[j][i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[b][a] = true;
	}

	selectLine(1, 0);

	if (ans == INF) ans = -1;

	cout << ans << "\n";

	return 0;
}