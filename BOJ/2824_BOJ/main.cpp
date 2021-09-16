#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000000;

int arrN[1001];
int arrM[1001];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	int i, j;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> arrN[i];
	}
	cin >> m;

	bool biggg = false;
	long long sum = 1;
	
	for (i = 0; i < m; i++) {
		cin >> arrM[i];
		for (j = 0; j < n; j++) {
			if (arrM[i] == 1) break;
			if (arrN[j] == 1) continue;
	
			int g = gcd(arrM[i], arrN[j]);

			sum *= g;
	
			arrM[i] /= g;
			arrN[j] /= g;
			if (sum > MOD) {
				sum = sum % MOD + MOD;
			}
		}
	}

	string ans = "";
	ans = to_string(sum);
	if (sum > MOD) {
		ans = ans.substr(1, ans.length());
	}

	cout << ans;
	
	return 0;
}