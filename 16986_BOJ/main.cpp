#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int map[10][10];
int rsp[4][21];
int win[4];
int turn[4];
bool ans = false;

bool rspOverlap(int num) {
	for (int i = 0; i < turn[1]; i++)
		if (rsp[1][i] == num)
			return true;
	return false;
}

void dfs(int player1, int player2) {
	if (win[1] == k) {
		ans = true;
		return;
	}

	if (win[2] == k || win[3] == k)
		return;

	if (turn[1] > n || ans == true)
		return;

	for (int i = 1; i <= n; i++) {
		if (player1 != 1 && player2 != 1) {
			i = n;
		}
		else {
			if (rspOverlap(i))
				continue;
			rsp[1][turn[1]] = i;
		}

		int winner = 0;
		int n1 = rsp[player1][turn[player1]];
		int n2 = rsp[player2][turn[player2]];

		if (map[n1][n2] == 2) winner = player1;
		else if (map[n1][n2] == 0) winner = player2;
		else winner = (player1 < player2) ? player2 : player1;

		turn[player1]++;
		turn[player2]++;
		win[winner]++;
		dfs(winner, 6 - (player1 + player2));
		turn[player1]--;
		turn[player2]--;
		win[winner]--;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	for (int j = 0; j < 20; j++)
		cin >> rsp[2][j];
	for (int j = 0; j < 20; j++)
		cin >> rsp[3][j];

	dfs(1, 2);
	if (ans) cout << 1 << "\n";
	else cout << 0 << "\n";

	return 0;
}