#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define APPLE 1
#define SNAKE -1

using namespace std;

int board[101][101] = { 0, };
int d[10001];
int totalSec = 0;
int N, K, L, curDir = 0;
pair<int, int> head;
queue<pair<int, int>> q;

int dir[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

bool canMove() {

	int nx = q.back().first + dir[curDir][0];
	int ny = q.back().second + dir[curDir][1];
	
	if (nx < 0 || ny < 0 || nx >= N || ny >= N)
		return false;

	// 벽에 닿거나 자신의 몸과 부딪히면 게임 끝
	for (int i = 0; i < q.size(); i++) 
		if (board[nx][ny] == SNAKE) 
			return false;

	q.push({ nx, ny });
	if (board[nx][ny] != APPLE) {
		int x = q.front().first;
		int y= q.front().second;
		board[x][y] = 0;
		q.pop();
	}
	board[nx][ny] = SNAKE;

	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		board[a - 1][b - 1] = APPLE;
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int sec;
		char c;
		cin >> sec >> c;
		d[sec] = c;
	}
	q.push({ 0, 0 });

	for (totalSec = 1; ; totalSec++) {
		if (!canMove()) break;

		if (d[totalSec] == 'D')  // 오른쪽 90도
			curDir = (curDir + 1) % 4;
		else if (d[totalSec] == 'L')  // 왼쪽 90도
			curDir = (curDir + 4 - 1) % 4;
	}

	cout << totalSec << "\n";

	return 0;
}