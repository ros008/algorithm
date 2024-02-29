#include <iostream>
#include <algorithm>

using namespace std;


long long fib(int n) {
	long long nums[91];

	nums[0] = 0;
	nums[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		nums[i] = nums[i - 1] + nums[i - 2];
	}
	return nums[n];
}

int main() {
	int n;


	cin >> n;
	cout << fib(n);


	return 0;
}