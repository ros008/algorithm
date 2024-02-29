#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int roomMap[51][51];
int tmpMap[51][51];
int r, c, t;
pair<int, int> upCleaner;
pair<int, int> downCleaner;
bool flag = false;

void printMap() {
	cout << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << roomMap[i][j] << " ";
		}
		cout << "\n";
	}
}

void copyMap() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			roomMap[i][j] = tmpMap[i][j];
}

void dustDiffuse() {
	memset(tmpMap, 0, sizeof(tmpMap));
	int quo, cnt = 0;;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (roomMap[i][j] > 0) {
				quo = roomMap[i][j] / 5;
				cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ni = i + dr[k];
					int nj = j + dc[k];
					if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
					if (roomMap[ni][nj] == -1) continue;
					tmpMap[ni][nj] += quo;
					cnt++;
				}
				tmpMap[i][j] += roomMap[i][j] - (cnt * quo);
			}
		}
	}
	tmpMap[upCleaner.first][upCleaner.second] = -1;
	tmpMap[downCleaner.first][downCleaner.second] = -1;
	copyMap();
}

void airCleaner() {
	int x, i;
	// À§
	x = upCleaner.first;
	roomMap[x - 1][0] = 0;
	for (i = 1; i < x; i++) 
		swap(roomMap[x - i][0], roomMap[x - (i + 1)][0]);
	for (i = 0; i < c - 1; i++)
		swap(roomMap[0][i], roomMap[0][i + 1]);
	for (i = 0; i < x; i++)
		swap(roomMap[i][c - 1], roomMap[i + 1][c - 1]);
	for (i = 1; i < c - 1; i++)
		swap(roomMap[x][c - i], roomMap[x][c - (i + 1)]);

	// ¾Æ·¡
	x = downCleaner.first;
	roomMap[x + 1][0] = 0;
	for (i = 1; i < r - x - 1; i++)
		swap(roomMap[x + i][0], roomMap[x + (i + 1)][0]);
	for (i = 0; i < c - 1; i++)
		swap(roomMap[r - 1][i], roomMap[r - 1][i + 1]);
	for (i = r - 1; i >= x + 1; i--)
		swap(roomMap[i][c - 1], roomMap[i - 1][c - 1]);
	for (i = 1; i < c - 1; i++)
		swap(roomMap[x][c - i], roomMap[x][c - (i + 1)]);
}

int cntDust() {
	int cnt = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (roomMap[i][j] != -1)
				cnt += roomMap[i][j];

	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> roomMap[i][j];
			if (roomMap[i][j] == -1) {
				if (!flag) {
					upCleaner = { i,j };
					flag = true;
				}
				else
					downCleaner = { i,j };
			}
		}
	}

	while (t--) {
		dustDiffuse();
		//printMap();

		airCleaner();
		//printMap();
	}

	cout << cntDust();

	return 0;
}