#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int power(int n, int m) {
	if (m == 1)
		return n;
	return power(n, m - 1) * n;
}

int main() {

	for (int i = 1; i <= 10; i++) {
		int tc;
		int N, M;

		cin >> tc;
		cin >> N >> M;

		cout << "#" << tc << " " << power(N, M) << "\n";
	}

	return 0;
}