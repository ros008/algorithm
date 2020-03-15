#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int minCost;
int oneDay, oneMonth, threeMonth, oneYear;
int plan[12];


void dfs(int month, int curCost) {
	if (curCost > minCost) return;

	if (month >= 12) {
		minCost = min(minCost, curCost);
		return;
	}

	if (plan[month] == 0) dfs(month + 1, curCost);

	int tmp[12];
	// 1일권
	tmp[month] = plan[month];
	plan[month] = 0;
	dfs(month + 1, curCost + tmp[month] * oneDay);
	plan[month] = tmp[month];

	// 1달권
	tmp[month] = plan[month];
	plan[month] = 0;
	dfs(month + 1, curCost + oneMonth);
	plan[month] = tmp[month];

	// 3달권
	for (int i = 0; i < 3; i++) tmp[(month + i) % 12] = plan[(month + i) % 12];
	for (int i = 0; i < 3; i++) plan[(month + i) % 12] = 0;
	dfs(month + 3, curCost + threeMonth);
	for (int i = 0; i < 3; i++) plan[(month + i) % 12] = tmp[(month + i) % 12];
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		cin >> oneDay >> oneMonth >> threeMonth >> oneYear;
		minCost = oneYear;
		for (int i = 0; i < 12; i++)
			cin >> plan[i];
		dfs(0, 0);

		cout << "#" << T << " " << minCost << "\n";
	}
	return 0;
}