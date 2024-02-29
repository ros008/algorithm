#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;

	while (1) {
		cin >> n;
		if (cin.eof()) {
			break;
		}

		long long rem = 1;
		long long cnt = 1;

		while (1) {
			if (rem % n == 0) break;

			rem = (rem * 10) % n + 1;
			cnt++;
		}

		cout << cnt << "\n";

	}

	return 0;
}