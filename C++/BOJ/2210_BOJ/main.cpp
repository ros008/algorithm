#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

set<int> s;
int map[5][5];

void makeStr(int x, int y, int sum, int cnt) {
	if (cnt == 5) {
		s.insert(sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

		makeStr(nx, ny, sum * 10 + map[nx][ny], cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];


	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			makeStr(i, j, map[i][j], 0);
	
	cout << s.size() << "\n";

	return 0;
}