#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define INF 987654321

using namespace std;

int n, w;
int dp[1001][1001], way[1001];
pair<int, int> saggeon[1001];

int getdist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int getMinDis(int x, int y) {
	if (x == w || y == w)
		return 0;

	if (dp[x][y] != -1)
		return dp[x][y];

	int op1, op2;
	pair<int, int> to;
	
	if (x == 0) to = { 1,1 };
	else to = saggeon[x];
	op1 = getMinDis(max(x, y) + 1, y) + getdist(saggeon[max(x, y) + 1], to);
	
	if (y == 0) to = { n,n };
	else to = saggeon[y];
	op2 = getMinDis(x, max(x, y) + 1) + getdist(saggeon[max(x, y) + 1], to);

	return dp[x][y] = min(op1, op2);
}

void getWay(int x, int y) {
	if (x == w || y == w)
		return;

	int op1, op2;
	pair<int, int> to;
	
	if (x == 0) to = { 1,1 };
	else to = saggeon[x];
	op1 = getMinDis(max(x, y) + 1, y) + getdist(saggeon[max(x, y) + 1], to);

	if (y == 0) to = { n,n };
	else to = saggeon[y];
	op2 = getMinDis(x, max(x, y) + 1) + getdist(saggeon[max(x, y) + 1], to);

	if (op1 < op2) {
		way[max(x, y) + 1] = 1;
		getWay(max(x, y) + 1, y);
	}
	else {
		way[max(x, y) + 1] = 2;
		getWay(x, max(x, y) + 1);
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	
	cin >> n >> w;

	for (int i = 1; i <= w; i++) 
		cin >> saggeon[i].first >> saggeon[i].second;
	
	cout << getMinDis(0, 0) << "\n";
	
	getWay(0, 0);
	for (int i = 1; i <= w; i++)
		cout << way[i] << "\n";

	return 0;
}