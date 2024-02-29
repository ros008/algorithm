#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct chess {
	int x;
	int y;
	int dir;
};

const int dx[] = { 0,0,0,-1,1 };
const int dy[] = { 0,1,-1,0,0 };

bool flag = false;
int n, k;
int board[13][13];
vector<int> boardState[13][13];
chess mal[11];
int turnCnt = 0;

int findPos(int x, int y, int idx) { // 해당 칸에 몇번째에 존재하는지
	for (int i = 0; i < boardState[x][y].size(); i++) 
		if (boardState[x][y][i] == idx) 
			return i;
}

bool checkFour() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (boardState[i][j].size() >= 4)
				return true;
	return false;
}

int reverseDir(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4; 
	else if (d == 4) return 3;
}

// 체스는 i번째 체스이고 x,y에 존재 다음 옮길 칸은 nx, ny
void moveChess(int chessNum, int x, int y, int nx, int ny) {
	int pos = findPos(x, y, chessNum); // x,y에서 몇번째에 존재했는지
	int nextColor;
	
	if (nx<1 || nx>n || ny<1 || ny>n) nextColor = 2;
	else nextColor = board[nx][ny];

	if (nextColor == 0) { // 다음 칸이 흰색
		for (int i = pos; i < boardState[x][y].size(); i++) {
			boardState[nx][ny].push_back(boardState[x][y][i]);
			mal[boardState[x][y][i]].x = nx;
			mal[boardState[x][y][i]].y = ny;
  		}
		int s = boardState[x][y].size() - 1;
		for (int i = s; i >= 0; i--) {
			if (boardState[x][y][i] == chessNum) {
				boardState[x][y].pop_back();
				break;
			}
			boardState[x][y].pop_back();
		}
	}
	else if (nextColor == 1) { // 다음 칸이 빨간색
		for (int i = boardState[x][y].size() - 1; i >=pos; i--) {
			boardState[nx][ny].push_back(boardState[x][y][i]);
			mal[boardState[x][y][i]].x = nx;
			mal[boardState[x][y][i]].y = ny;
		}
		int s = boardState[x][y].size() - 1;
		for (int i = s; i >= 0; i--) {
			if (boardState[x][y][i] == chessNum) {
				boardState[x][y].pop_back();
				break;
			}
			boardState[x][y].pop_back();
		}
	}
	else if (nextColor == 2) { // 다음 칸이 파란색
		int nDir = reverseDir(mal[chessNum].dir);

		mal[chessNum].dir = nDir;
		int nnx = x + dx[nDir];
		int nny = y + dy[nDir];

		if (nnx >= 1 && nnx <= n && nny >= 1 && nny <= n)
			if (board[nnx][nny] != 2)
				moveChess(chessNum, x, y, nnx, nny);
	}
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	for (int i = 1; i <= k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mal[i] = { a,b,c };
		boardState[a][b].push_back(i);
	}


	while (1) {
		if (turnCnt > 1000) break;

		for (int i = 1; i <= k; i++) {
			int x = mal[i].x;
			int y = mal[i].y;
			int dir = mal[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			moveChess(i, x, y, nx, ny);
			if (checkFour()) {
				flag = true;
				break;
			}
		}
		if (flag) break;
		turnCnt++;
	}

	if (flag) cout << turnCnt + 1 << "\n";
	else cout << -1 << "\n";

	return 0;
}