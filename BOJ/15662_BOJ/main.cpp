#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, k;
string tobni[1001];
int directions[1001];

void rotateTobni() {
	for (int i = 1; i <= t; i++) {
		if (directions[i] == 1) { // 시계
			for (int k = 7; k >= 1; k--)
				swap(tobni[i][k], tobni[i][k - 1]);
		}
		else if (directions[i] == -1) { // 반시계
			for (int k = 0; k < 7; k++)
				swap(tobni[i][k], tobni[i][k + 1]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;
	for (int i = 1; i <= t; i++)
		cin >> tobni[i];
	cin >> k;

	while (k--) {
		memset(directions, 0, sizeof(directions));

		int tobniNum, dir;
		cin >> tobniNum >> dir;
		directions[tobniNum] = dir;

		int i = tobniNum - 1;
		while (i > 0) {
			if (tobni[i][2] == tobni[i + 1][6]) {
				break;
			}
			else {
				directions[i] = directions[i + 1] * -1;
			}
			i--;
		}

		i = tobniNum + 1;
		while (i <= t) {
			if (tobni[i][6] == tobni[i - 1][2]) {
				break;
			}
			else {
				directions[i] = directions[i - 1] * -1;
			}
			i++;
		}

		rotateTobni();
	}

	int cnt = 0;
	for (int i = 1; i <= t; i++)
		if (tobni[i][0] == '1')
			cnt++;

	cout << cnt << "\n";

	return 0;
}