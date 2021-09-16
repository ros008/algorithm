#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
ll dp[2003][2003];
vector<ll> cake;

ll ICutCake(int l, int r);
ll JCutCake(int l, int r);

ll ICutCake(int l, int r) { // I는 무조건 큰 것 가져감
	if ((r + 1) % n == l) return 0; // 이미 다 가져갔다면
	if (cake[(l - 1 + n) % n] > cake[(r + 1) % n])
		return JCutCake((l - 1 + n) % n, r); // l이 더 크다면 l 가져감
	else
		return JCutCake(l, (r + 1) % n); // r이 더 크다면 r 가져감
}

ll JCutCake(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r]; // 이미 방문했다면 dp return
	if ((r + 1) % n == l) return dp[l][r] = 0; // 이미 다 가져갔다면
	ll opt1 = cake[(l - 1 + n) % n] + ICutCake((l - 1 + n) % n, r);
	ll opt2 = cake[(r + 1) % n] + ICutCake(l, (r + 1) % n);
	return dp[l][r] = max(opt1, opt2);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n; 
	cake.resize(n);

	for (int i = 0; i < n; i++)
		cin >> cake[i];
	ll ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		ans = max(ans, cake[i] + ICutCake(i, i));
	// i번째 가져간후, 가장 왼쪽이 i이고 가장 오른쪽이 r이다. 
	// 다음으로 가져 갈 수 있는 것은 l-1, r+1

	cout << ans << "\n";
	

	return 0;
}