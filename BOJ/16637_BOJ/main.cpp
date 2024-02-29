#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define INF 987654321

using namespace std;

int n, ans = -INF;
string str;

int calcul(int a, int b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else
		return a * b;
}

void solve(int idx, int cur) {
	if (idx >= n) {
		ans = max(ans, cur);
		return;
	}
	char oper = (idx == 0) ? '+' : str[idx - 1];

	if (idx + 2 < n) {
		int bracket = calcul(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		solve(idx + 4, calcul(cur, bracket, oper));
	}
	solve(idx + 2, calcul(cur, str[idx] - '0', oper));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> str;

	solve(0, 0);

	cout << ans << "\n";

	return 0;
}