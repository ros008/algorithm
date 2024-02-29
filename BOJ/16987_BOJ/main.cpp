#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans;
int s[8];
int w[8];

void dfs(int idx) {
	if (idx == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			if (s[i] <= 0) 
				cnt++;
		ans = max(ans, cnt);
		return;
	}

	if (s[idx] <= 0) dfs(idx + 1);
	else {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			if (i == idx || s[i] <= 0) continue;
			s[idx] -= w[i];
			s[i] -= w[idx];
			dfs(idx + 1);
			s[idx] += w[i];
			s[i] += w[idx];
		}
		if (flag == false) dfs(n);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> s[i] >> w[i];
	
	dfs(0);
	cout << ans << "\n";

	return 0;
}