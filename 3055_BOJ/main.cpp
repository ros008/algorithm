#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define MAX 51

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int R, C;
char mapForest[MAX][MAX];
int waterMap[MAX][MAX];
bool visited[MAX][MAX];

pair<int, int> startPos;
pair<int, int> endPos;

queue<pair<int, int>> waterQ;

// 입력 받고 watermap, startpos, endpos, mapforest 초기화 해주는 함수
void Init() {
	cin >> R >> C;
	//watermap 초기화
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			waterMap[i][j] = 1000;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mapForest[i][j];
			if (mapForest[i][j] == 'S') {
				startPos.first = i;
				startPos.second = j;
			}
			else if (mapForest[i][j] == 'D') {
				endPos.first = i;
				endPos.second = j;
			}
			else if (mapForest[i][j] == '*') {
				waterMap[i][j] = 0;
				waterQ.push(make_pair(i, j));
			}
		}
	}
}

// watermap 만드는 함수
void MakeWaterMap() {
	while (!waterQ.empty()) {
		int qsize = waterQ.size();
		for (int i = 0; i < qsize; i++) {
			int x = waterQ.front().first;
			int y = waterQ.front().second;
			waterQ.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
					if (mapForest[nx][ny] == '.') {
						if (waterMap[nx][ny] > waterMap[x][y] + 1) {
							waterMap[nx][ny] = waterMap[x][y] + 1;
							waterQ.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Init();
	MakeWaterMap();

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(startPos.first, startPos.second), 0));
	visited[startPos.first][startPos.second] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == endPos.first && y == endPos.second) {
			cout << cnt << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (visited[nx][ny] == false && mapForest[nx][ny] != 'X' && waterMap[nx][ny] > cnt + 1) {
					visited[nx][ny] = 1;
					q.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}
	}
	cout << "KAKTUS" << "\n";

	return 0;
}