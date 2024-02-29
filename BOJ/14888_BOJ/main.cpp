#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1000000007

using namespace std;

int n;
int a[12];
int oper[4];
int minVal = INF, maxVal = -INF;

void getMinMax(int cur, int idx) {
	if (idx == n) {
		minVal = min(minVal, cur);
		maxVal = max(maxVal, cur);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			
			if (i == 0)
				getMinMax(cur + a[idx], idx + 1);
			else if (i == 1)
				getMinMax(cur - a[idx], idx + 1);
			else if (i == 2)
				getMinMax(cur * a[idx], idx + 1);
			else if (i == 3)
				getMinMax(cur / a[idx], idx + 1);

			oper[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	getMinMax(a[0], 1);

	cout << maxVal << "\n" << minVal << "\n";

	return 0;
}