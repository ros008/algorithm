#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;
int board[8][8];
int boardCopy[8][8];
bool check[64];
int maxSafe = 0;

vector<pair<int, int>> virus;

void countSafe() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (boardCopy[i][j] == 0)
				cnt++;
	maxSafe = max(maxSafe, cnt);
}

void BFS() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++)
		q.push({ virus[i].first, virus[i].second });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (boardCopy[nx][ny] == 0) {
					boardCopy[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}

	countSafe();
}

void makeWall(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				boardCopy[i][j] = board[i][j];
		BFS();
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				makeWall(cnt + 1);
				board[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) 
				virus.push_back({ i,j });
		}
	}
		
	makeWall(0);

	cout << maxSafe << "\n";

	return 0;
}