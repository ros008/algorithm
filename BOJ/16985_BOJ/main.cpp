#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define INF 987654321

using namespace std;

int dh[] = { -1,0,1,0,0,0 };
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,1,0,-1,0,0 };

const int n = 5;

int ans = INF;
vector<vector<vector<int>>> cube(6, vector<vector<int>>(6, vector<int>(6)));
vector<vector<vector<int>>> cubeCopied(6, vector<vector<int>>(6, vector<int>(6)));;
bool visited[6][6][6];
int mazeOrder[6];
int mazeTurn[6];

void bfs() {
	memset(visited, false, sizeof(visited));

	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{0,0} }); // 거리, h, x, y
	visited[0][0][0] = true;

	while (!q.empty()) {
		int dist = q.front().first.first;
		int h = q.front().first.second;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == n - 1 && h == n - 1) {
			ans = min(ans, dist);
			return;
		}
			
		for (int i = 0; i < 6; i++) {
			int nh = h + dh[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nh >= 0 && nh < n && nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (cubeCopied[nh][nx][ny] == 1 && !visited[nh][nx][ny]) {
					q.push({ {dist + 1, nh},{nx, ny} });
					visited[nh][nx][ny] = true;
				}
			}
		}
	}
}

void makeMazeTurn(int idx) {
	vector<vector<int>> tmp(6, vector<int>(6));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][j] = cubeCopied[idx][j][4 - i];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cubeCopied[idx][i][j] = tmp[i][j];
}

void solve(){
	for (int a = 0; a < 4; a++) {
		makeMazeTurn(0);
		if (cubeCopied[0][0][0] != 1) continue;
		for (int b = 0; b < 4; b++) {
			makeMazeTurn(1);
			for (int c = 0; c < 4; c++) {
				makeMazeTurn(2);
				for (int d = 0; d < 4; d++) {
					makeMazeTurn(3);
					for (int e = 0; e < 4; e++) {
						makeMazeTurn(4);
						if (cubeCopied[4][4][4] == 1) 
							bfs();
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> cube[k][i][j];

	vector<int> order;
	for (int i = 0; i < n; i++)
		order.push_back(i);
	
	// 판의 순서 정하기
	do {
		for (int i = 0; i < n; i++)
			cubeCopied[order[i]] = cube[i];
		
		solve();

	} while (next_permutation(order.begin(), order.end()));

	if (ans == INF) cout << -1 << "\n";
	else cout << ans << "\n";

	return 0;
}