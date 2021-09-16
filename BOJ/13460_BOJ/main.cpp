#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int n, m;
char map[11][11];

pair<int, int> R;
pair<int, int> B;
pair<int, int> dest;

void bfs() {

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				R = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				B = { i,j };
				map[i][j] = '.';
			}
		}
	}
	


	return 0;
}