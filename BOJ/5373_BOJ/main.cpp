#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotateClockwise(int idx, char cube[6][3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			char tmp = cube[idx][i][j];
			cube[idx][i][j] = cube[idx][j][i];
			cube[idx][j][i] = tmp;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		char tmp = cube[idx][i][0];
		cube[idx][i][0] = cube[idx][i][2];
		cube[idx][i][2] = tmp;
	}
}

void rotateCounterClockwise(int idx, char cube[6][3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			char tmp = cube[idx][i][j];
			cube[idx][i][j] = cube[idx][j][i];
			cube[idx][j][i] = tmp;
		}
	}

	for (int i = 0; i < 3; i++) {
		char tmp = cube[idx][0][i];
		cube[idx][0][i] = cube[idx][2][i];
		cube[idx][2][i] = tmp;
	}
}

void rotateCube(char idx, char dir, char cube[6][3][3]) {
	if (idx == 'U') {
		if (dir == '+') {
			rotateClockwise(0, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[1][0][i];
				cube[1][0][i] = cube[5][0][i];
				cube[5][0][i] = cube[3][2][2 - i];
				cube[3][2][2 - i] = cube[4][0][i];
				cube[4][0][i] = tmp;
			}
		}
		else if (dir == '-') {
			rotateCounterClockwise(0, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[1][0][i];
				cube[1][0][i] = cube[4][0][i];
				cube[4][0][i] = cube[3][2][2 - i];
				cube[3][2][2 - i] = cube[5][0][i];
				cube[5][0][i] = tmp;
			}
		}
	}
	else if (idx == 'D') {
		if (dir == '+') {
			rotateClockwise(2, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[3][0][i];
				cube[3][0][i] = cube[5][2][2 - i];
				cube[5][2][2 - i] = cube[1][2][2 - i];
				cube[1][2][2 - i] = cube[4][2][2 - i];
				cube[4][2][2 - i] = tmp;
			}
		}
		else if (dir == '-') {
			rotateCounterClockwise(2, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[3][0][i];
				cube[3][0][i] = cube[4][2][2 - i];
				cube[4][2][2 - i] = cube[1][2][2 - i];
				cube[1][2][2 - i] = cube[5][2][2 - i];
				cube[5][2][2 - i] = tmp;
			}
		}
	}
	else if (idx == 'F') {
		if (dir == '+') {
			rotateClockwise(1, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[2][0][i];
				cube[2][0][i] = cube[5][2 - i][0];
				cube[5][2 - i][0] = cube[0][2][2 - i];
				cube[0][2][2 - i] = cube[4][i][2];
				cube[4][i][2] = tmp;
			}
		}
		else if (dir == '-') {
			rotateCounterClockwise(1, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[2][0][i];
				cube[2][0][i] = cube[4][i][2];
				cube[4][i][2] = cube[0][2][2 - i];
				cube[0][2][2 - i] = cube[5][2 - i][0];
				cube[5][2 - i][0] = tmp;
			}
		}
	}
	else if (idx == 'B') {
		if (dir == '+') {
			rotateClockwise(3, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[0][0][i];
				cube[0][0][i] = cube[5][i][2];
				cube[5][i][2] = cube[2][2][2 - i];
				cube[2][2][2 - i] = cube[4][2 - i][0];
				cube[4][2 - i][0] = tmp;
			}
		}
		else if (dir == '-') {
			rotateCounterClockwise(3, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[0][0][i];
				cube[0][0][i] = cube[4][2 - i][0];
				cube[4][2 - i][0] = cube[2][2][2 - i];
				cube[2][2][2 - i] = cube[5][i][2];
				cube[5][i][2] = tmp;
			}
		}
	}
	else if (idx == 'L') {
		if (dir == '+') {
			rotateClockwise(4, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[2][i][0];
				cube[2][i][0] = cube[1][i][0];
				cube[1][i][0] = cube[0][i][0];
				cube[0][i][0] = cube[3][i][0];
				cube[3][i][0] = tmp;
			}
		}
		else if (dir == '-') {
			rotateCounterClockwise(4, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[2][i][0];
				cube[2][i][0] = cube[3][i][0];
				cube[3][i][0] = cube[0][i][0];
				cube[0][i][0] = cube[1][i][0];
				cube[1][i][0] = tmp;
			}
		}
	}
	else if (idx == 'R') {
		if (dir == '+') {
			rotateClockwise(5, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[2][i][2];
				cube[2][i][2] = cube[3][i][2];
				cube[3][i][2] = cube[0][i][2];
				cube[0][i][2] = cube[1][i][2];
				cube[1][i][2] = tmp;
			}
		}
		else if (dir == '-') {
			rotateCounterClockwise(5, cube);
			for (int i = 0; i < 3; i++) {
				char tmp = cube[2][i][2];
				cube[2][i][2] = cube[1][i][2];
				cube[1][i][2] = cube[0][i][2];
				cube[0][i][2] = cube[3][i][2];
				cube[3][i][2] = tmp;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		char cube[6][3][3] = {
			{ {'w','w','w'},{'w','w','w'},{'w','w','w'} },
			{ {'r','r','r'},{'r','r','r'},{'r','r','r'} },
			{ {'y','y','y'},{'y','y','y'},{'y','y','y'} },
			{ {'o','o','o'},{'o','o','o'},{'o','o','o'} },
			{ {'g','g','g'},{'g','g','g'},{'g','g','g'} },
			{ {'b','b','b'},{'b','b','b'},{'b','b','b'} }
		};
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char myun, dir;
			cin >> myun >> dir;
			rotateCube(myun, dir, cube);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}