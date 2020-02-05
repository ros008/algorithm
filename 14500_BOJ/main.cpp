#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int map[501][501];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];



	return 0;
}