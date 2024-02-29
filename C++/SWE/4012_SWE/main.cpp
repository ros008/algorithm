#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;
int synergy[17][17];
int selected[17];

int getSynergy(int num) {
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (selected[i] == num && selected[j] == num)
				ret += synergy[i][j];
	return ret;
}

int solve(int idx, int selectedNum) {
	if (idx == N) {
		if (selectedNum == N / 2) {
			int sum0 = getSynergy(0);
			int sum1 = getSynergy(1);
			return abs(sum0 - sum1);
		}
		else 
			return INF;
	}

	int ret = INF;
	selected[idx] = 1;
	ret = min(ret, solve(idx + 1, selectedNum + 1));
	selected[idx] = 0;
	ret = min(ret, solve(idx + 1, selectedNum));

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> synergy[i][j];

		cout << "#" << T << " " << solve(0, 0) << "\n";
	}

	return 0;
}