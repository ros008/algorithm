#include <iostream>

#define INF 987654321

using namespace std;

int N;
int arr[12];
int oper[4]; // + - * /
int minVal, maxVal;

void calcul(int idx, int curVal, int p, int m, int mul, int div) {
	if (idx == N - 1) {
		if (maxVal < curVal) maxVal = curVal;
		if (minVal > curVal) minVal = curVal;
		return;
	}

	if (p > 0) {
		calcul(idx + 1, curVal + arr[idx + 1], p - 1, m, mul, div);
	}
	if (m > 0) {
		calcul(idx + 1, curVal - arr[idx + 1], p, m - 1, mul, div);
	}
	if (mul > 0) {
		calcul(idx + 1, curVal * arr[idx + 1], p, m, mul - 1, div);
	}
	if (div > 0) {
		calcul(idx + 1, curVal / arr[idx + 1], p, m, mul, div - 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> N;
		for (int i = 0; i < 4; i++)
			cin >> oper[i];
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		minVal = INF; maxVal = -INF;
		calcul(0, arr[0], oper[0], oper[1], oper[2], oper[3]);

		cout << "#" << T << " " << abs(minVal - maxVal) << "\n";
	}


	return 0;
}