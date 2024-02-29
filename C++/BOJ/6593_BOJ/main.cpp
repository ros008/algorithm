#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct building {
	int l;
	int r;
	int c;
};

const int dl[] = { -1,0,1,0,0,0 };
const int dr[] = { 0,0,0,0,1,-1 };
const int dc[] = { 0,1,0,-1,0,0 };

const int INF = 987654321;
const int MAX = 30 + 1;

int L, R, C;
char map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
building start, dest;

int dijkstra(building src) {
	for (int k = 1; k <= L; k++)
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				visited[k][i][j] = false;

	queue<pair<int, building>> q;
	q.push({ 0,{src.l, src.r, src.c} });
	visited[src.l][src.r][src.c] = true;

	while (!q.empty()) {
		int curL = q.front().second.l;
		int curR = q.front().second.r;
		int curC = q.front().second.c;
		int curDist = q.front().first;
		q.pop();

		if (curL == dest.l && curR == dest.r && curC == dest.c)
			return curDist;

		for (int i = 0; i < 6; i++) {
			int nL = curL + dl[i];
			int nR = curR + dr[i];
			int nC = curC + dc[i];
			int nDist = curDist + 1;

			if (nL >= 1 && nL <= L && nR >= 1 && nR <= R && nC >= 1 && nC <= C) {
				if (map[nL][nR][nC] != '#' && !visited[nL][nR][nC]) {
					q.push({ nDist,{nL,nR,nC} });
					visited[nL][nR][nC] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int k = 1; k <= L; k++) {
			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					cin >> map[k][i][j];
					if (map[k][i][j] == 'E') {
						dest.l = k;
						dest.r = i;
						dest.c = j;
					}
					else if (map[k][i][j] == 'S') {
						start.l = k;
						start.r = i;
						start.c = j;
						map[k][i][j] = '.';
					}
				}
			}
		}

		int ans = dijkstra(start);
		if (ans == -1)
			cout << "Trapped!" << "\n";
		else
			cout << "Escaped in " << ans << " minute(s)." << "\n";
	}


	return 0;
}