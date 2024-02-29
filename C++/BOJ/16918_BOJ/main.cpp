#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int r, c, n;
char map[201][201];
int boomTime[201][201];

void intstallBomb(int t) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'O') continue;
			map[i][j] = 'O';
			boomTime[i][j] = t + 3;
		}
	}
}

void bombBomb(int t) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (boomTime[i][j] == t) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (map[nx][ny] == '.') continue;
					map[nx][ny] = '.';
				}
				map[i][j] = '.';
				boomTime[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O')
				boomTime[i][j] = 3;
		}
	}

	int curTime = 2;
	while (1) {
		// ¼³Ä¡
		if (curTime == n + 1) {
			break;
		}
		else if (curTime % 2 == 0) {
			intstallBomb(curTime);
		}
		else { // Æø¹ß
			bombBomb(curTime);
		}
		curTime++;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) 
			cout << map[i][j];
		cout << "\n";
	}

	return 0;
}