#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	if (N < 100) {
		cout << N;
	}
	else {
		int result = 0;
		for (int i = 100; i <= N; i++) {
			int hund = (i / 100);
			int ten = (i % 100) / 10;
			int one = (i % 100) % 10;
			if (hund - ten == ten - one)
				result++;
		}
		cout << 99 + result;
	}

	return 0;
}