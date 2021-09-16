#include <iostream>
#include <algorithm>

#define INF 1000000007

using namespace std;

int n;
int playerStat[21][21];
bool check[21];
int minDiff = INF;

void countDiff() {
	int teamA = 0, teamB = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i] == true && check[j] == true && (i != j))
				teamA += playerStat[i][j];
			else if (check[i] == false && check[j] == false && (i != j))
				teamB += playerStat[i][j];
		}
	}
	minDiff = min(minDiff, abs(teamA - teamB));
}

void pickPlayer(int idx, int cnt) {
	if (cnt == n / 2) {
		countDiff();
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (check[i] == false) {
			check[i] = true;
			pickPlayer(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> playerStat[i][j];

	pickPlayer(1, 0);
	cout << minDiff << "\n";

	return 0;
}