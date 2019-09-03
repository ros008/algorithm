#include <iostream>
#include <algorithm>

using namespace std;

long long nums[101];

void fado(int n) {
	nums[1] = 1;
	nums[2] = 1;
	nums[3] = 1;
	nums[4] = 2;
	nums[5] = 2;

	for (int i = 6; i <= n; i++) {
		nums[i] = nums[i - 1] + nums[i - 5];
	}
}

int main() {

	int tc;
	cin >> tc;

	while (tc--) {
		int N;
		cin >> N;
		fado(N);

		cout << nums[N] << "\n";
	}

	return 0;
}