#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321

using namespace std;

int n, ans = -INF;
char str[20];

int calcul(int a, int b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	return 0;
}

void dfs(int idx) {

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> str[i];

	dfs(1);
	cout << ans << "\n";

	return 0;
}