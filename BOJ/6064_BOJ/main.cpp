#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;

	return gcd(y, x%y);
}

int lcm(int x, int y) {
	return 	x * y / gcd(x, y);
}

int main() {

	int tc;
	cin >> tc;

	while (tc--) {
		int M, N, x, y;
		int cnt = 0;
		int result = 0;
		
		cin >> M >> N >> x >> y;

		int gcdmn;
		int lcmmn;

		if (M > N) {
			gcdmn = gcd(M, N);
			lcmmn = lcm(M, N);
		}
		else {
			gcdmn = gcd(N, M);
			lcmmn = lcm(N, M);
		}

		for (int i = 0; ; i++) {
			int tmp = i * M + x;
			if (tmp > lcmmn) {
				break;
			}
			if (tmp % N == y) {
				result = tmp;
				break;
			}
			else if (tmp%N == 0 && N == y) {
				result = tmp;
				break;
			}
		}

		if (result == 0) cout << -1 << "\n";
		else cout << result << "\n";
	}

	return 0;
}