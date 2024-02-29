#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 101

using namespace std;

const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };

int n;
int x, y, d, g;
int map[MAX][MAX];
vector<int> dir;

void makeDragonCurve() {
	int s = dir.size();
	for (int i = s - 1; i >= 0; i--) {
		int nd = (dir[i] + 1) % 4;
		x = x + dx[nd];
		y = y + dy[nd];
		map[x][y] = 1;
		dir.push_back(nd);
	}
}

void cntSquare() {
	int cnt = 0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				cnt++;

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;
		dir.clear();

		map[x][y] = 1;
		x = x + dx[d];
		y = y + dy[d];
		map[x][y] = 1;

		dir.push_back(d);
		for (int j = 0; j < g; j++) {
			makeDragonCurve();
		}
	}

	cntSquare();

	return 0;
}