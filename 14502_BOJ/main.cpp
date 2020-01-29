#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int nr[4] = { 1,0,-1,0 };
int nc[4] = { 0,1,0,-1 };

int n, m;
int board[8][8];
int boardCopy[8][8];
bool check[64];
int maxSafe = 0;

vector<pair<int, int>> emp, virus;

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


}

void makeWall(int idx, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				boardCopy[i][j] = board[i][j];
		BFS();
	}

	for (int i = idx; i < emp.size(); i++) {
		if (check[i] == true) continue;
		check[i] = true;
		makeWall(i + 1, cnt + 1); //////////
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) emp.push_back({ i,j });
			else if (board[i][j] == 2) virus.push_back({ i,j });
		}
	}
		
	makeWall(0, 0);

	cout << maxSafe << "\n";

	return 0;
}