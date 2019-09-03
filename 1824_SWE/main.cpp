#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

int mem = 0;
int R, C;
char hyuk[22][22];
bool check[22][22][4][16];

// check[i][j][k][l]에서 i행 j열 에서 k방향으로 이동할 때, mem의 값이 l이다. 
// check의 3차원은 0:동 1:남 2:서 3:북으로 정의한다
// check


bool find(int r, int c, int dir) {
	bool ret = false;

	// 방향 변경하기
	if (hyuk[r][c] >= '0' && hyuk[r][c] <= '9') mem = hyuk[r][c] - '0';
	else if (hyuk[r][c] == '<' || (hyuk[r][c] == '_' && mem != 0)) dir = 2;
	else if (hyuk[r][c] == '>' || (hyuk[r][c] == '_' && mem == 0)) dir = 0;
	else if (hyuk[r][c] == '^' || (hyuk[r][c] == '|' && mem != 0)) dir = 3;
	else if (hyuk[r][c] == 'v' || (hyuk[r][c] == '|' && mem == 0)) dir = 1;
	else if (hyuk[r][c] == '+') mem == 15 ? mem = 0 : mem += 1;
	else if (hyuk[r][c] == '-') mem == 0 ? mem = 15 : mem -= 1;
	else if (hyuk[r][c] == '@') return true;

	// 무한 루프 확인
	if (check[r][c][dir][mem] == true) return false;
	else check[r][c][dir][mem] = true;

	// 다음으로 가야할 방향 정하기
	int nextR = r + dr[dir];
	int nextC = c + dc[dir];
	if (nextR == 0) nextR = R;
	else if (nextR > R) nextR = 1;
	if (nextC == 0) nextC = C;
	else if (nextC > C) nextC = 1;

	// ? 이 입력으로 들어왔을 때
	if (hyuk[r][c] == '?') {
		for (int i = 0; i < 4; i++) {
			nextR = r + dr[i];
			nextC = c + dc[i];
			if (nextR == 0) nextR = R;
			else if (nextR > R) nextR = 1;
			if (nextC == 0) nextC = C;
			else if (nextC > C) nextC = 1;

			ret = max(find(nextR, nextC, i), ret);
		}
		return ret;
	}
	else {
		return max(ret, find(nextR, nextC, dir));
	}

	return false;
}

int main() {

	int tc;

	cin >> tc;

	for (int k = 1; k <= tc; k++) {

		cin >> R >> C;

		memset(hyuk, -1, sizeof(hyuk));
		memset(check, 0, sizeof(check));
		mem = 0;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cin >> hyuk[i][j];
			}
		}


		cout << "#" << k << " " << (find(1, 1, 0) ? "YES" : "NO") << endl;
	}

	return 0;
}