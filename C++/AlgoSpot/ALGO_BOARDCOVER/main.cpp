#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int coverShape[4][3][2] = {
	{ {0, 0}, {0, 1}, {1, 0} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 1}, {1, 0} },
	{ {0, 0}, {1, 0}, {1, -1} }
};

int h, w;

// 덮을 수 있는 지 반환
bool setOrRemBlack(vector<vector<int>>& arr, int y, int x, int type, int bw) {
	bool ret = true;
	for (int i = 0; i < 3; i++) {
		int ny = y + coverShape[type][i][0];
		int nx = x + coverShape[type][i][1];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w)
			ret = false;
		else if ((arr[ny][nx] += bw) > 1)
			ret = false;
	}
	return ret;
}

// 덮는 경우의 수 반환
int cover(vector<vector<int>>& arr) {
	int x = -1;
	int y = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 0) {
				x = j;
				y = i;
				break;
			}
		}
		if (y != -1) break;
	}
	// 기저사례
	if (x == -1)
		return 1;
	
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (setOrRemBlack(arr, y, x, i, 1))
			ret += cover(arr);
		setOrRemBlack(arr, y, x, i, -1);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		vector<vector<int>> arr(21, vector<int>(21, 0));
		cin >> h >> w;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char input;
				cin >> input;
				if (input == '#')
					arr[i][j] = 1;
				else if(input == '.')
					arr[i][j] = 0;
			}
		}

		cout << cover(arr) << "\n";
	}

	return 0;
}