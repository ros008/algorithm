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

ll ICutCake(int l, int r) { // I�� ������ ū �� ������
	if ((r + 1) % n == l) return 0; // �̹� �� �������ٸ�
	if (cake[(l - 1 + n) % n] > cake[(r + 1) % n])
		return JCutCake((l - 1 + n) % n, r); // l�� �� ũ�ٸ� l ������
	else
		return JCutCake(l, (r + 1) % n); // r�� �� ũ�ٸ� r ������
}

ll JCutCake(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r]; // �̹� �湮�ߴٸ� dp return
	if ((r + 1) % n == l) return dp[l][r] = 0; // �̹� �� �������ٸ�
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
	// i��° ��������, ���� ������ i�̰� ���� �������� r�̴�. 
	// �������� ���� �� �� �ִ� ���� l-1, r+1

	cout << ans << "\n";
	

	return 0;
}