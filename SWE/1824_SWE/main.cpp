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

// check[i][j][k][l]���� i�� j�� ���� k�������� �̵��� ��, mem�� ���� l�̴�. 
// check�� 3������ 0:�� 1:�� 2:�� 3:������ �����Ѵ�
// check


bool find(int r, int c, int dir) {
	bool ret = false;

	// ���� �����ϱ�
	if (hyuk[r][c] >= '0' && hyuk[r][c] <= '9') mem = hyuk[r][c] - '0';
	else if (hyuk[r][c] == '<' || (hyuk[r][c] == '_' && mem != 0)) dir = 2;
	else if (hyuk[r][c] == '>' || (hyuk[r][c] == '_' && mem == 0)) dir = 0;
	else if (hyuk[r][c] == '^' || (hyuk[r][c] == '|' && mem != 0)) dir = 3;
	else if (hyuk[r][c] == 'v' || (hyuk[r][c] == '|' && mem == 0)) dir = 1;
	else if (hyuk[r][c] == '+') mem == 15 ? mem = 0 : mem += 1;
	else if (hyuk[r][c] == '-') mem == 0 ? mem = 15 : mem -= 1;
	else if (hyuk[r][c] == '@') return true;

	// ���� ���� Ȯ��
	if (check[r][c][dir][mem] == true) return false;
	else check[r][c][dir][mem] = true;

	// �������� ������ ���� ���ϱ�
	int nextR = r + dr[dir];
	int nextC = c + dc[dir];
	if (nextR == 0) nextR = R;
	else if (nextR > R) nextR = 1;
	if (nextC == 0) nextC = C;
	else if (nextC > C) nextC = 1;

	// ? �� �Է����� ������ ��
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