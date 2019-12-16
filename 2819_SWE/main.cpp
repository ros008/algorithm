#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

set<string> strs;
vector<vector<int>> arr(4, vector<int>(4, 0));;

void getStr(int x, int y, int len, string str) {
	str += arr[x][y] + '0';
	len++;

	if (len == 7) {
		strs.insert(str);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)continue;
		getStr(nx, ny, len, str);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) 
				cin >> arr[i][j];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				getStr(i, j, 0, "");

		cout << "#" << tc << " " << strs.size() << "\n";
	}

	return 0;
}