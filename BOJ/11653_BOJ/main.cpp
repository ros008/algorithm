#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 2; i*i <= N; i++) {
		while (N%i == 0) {
			cout << i << '\n';
			N /= i;
		}
	}

	if (N != 1) {
		cout << N;
	}

	return 0;
}