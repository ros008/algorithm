#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int map[50][5];
int r1, c1, r2, c2;
int dir; // 현재 방향
int curX, curY; // 가상의 배열 rc
int num; // 현재 숫자
int total; // 입력한 총 숫자 개수
int len; // 방향 늘려가는
int goal;
int max_length;
int blank;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> r1 >> c1 >> r2 >> c2;
	goal = (abs(r2 - r1) + 1) * (abs(c2 - c1) + 1);
	dir = 3;
	curX = curY = 0;
	num = 1;
	total = 1;
	len = 0;


	if (curX >= r1 && curX <= r2 && curY >= c1 && curY <= c2) {
		map[curX - r1][curY - c1] = num;
		total++;
	}
	
	while (total <= goal) {
		dir = (dir + 1) % 4;
		if (dir == 0 || dir == 2) len++;

		for (int i = 0; i < len; i++) {
			curX += dx[dir];
			curY += dy[dir];
			num++;
			if (curX >= r1 && curX <= r2 && curY >= c1 && curY <= c2) {
				map[curX - r1][curY - c1] = num;
				total++;
				max_length = to_string(num).length();
			}
		}
	}

	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			blank = max_length - to_string(map[i][j]).size();
			for (int k = 0; k < blank; k++) cout << " ";
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}