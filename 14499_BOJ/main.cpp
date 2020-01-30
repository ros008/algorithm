#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// µ¿ ¼­ ºÏ ³²
int dx[5] = { 0 ,0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

int n, m, x, y, k;
int dice[6] = { 0, };
int board[21][21];

void move_dice(int dir) {
	switch (dir) {
	case 1: // µ¿
		swap(dice[3], dice[5]);
		swap(dice[5], dice[2]);
		swap(dice[2], dice[0]);
		break;
	case 2: // ¼­
		swap(dice[5], dice[3]);
		swap(dice[3], dice[0]);
		swap(dice[0], dice[2]);
		break;
	case 3: // ºÏ
		swap(dice[1], dice[0]);
		swap(dice[0], dice[4]);
		swap(dice[4], dice[5]);
		break;
	case 4: // ³²
		swap(dice[5], dice[4]);
		swap(dice[4], dice[0]);
		swap(dice[0], dice[1]);
		break;

	default:
		break;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	while (k--) {
		int d;
		cin >> d;

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		move_dice(d);

		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[5];
		}
		else {
			dice[5] = board[nx][ny];
			board[nx][ny] = 0;
		}

		cout << dice[0] << "\n";
		x = nx;
		y = ny;
	}

	return 0;
}