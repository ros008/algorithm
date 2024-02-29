#include <iostream>
#include <algorithm>

using namespace std;

long long numofzero[41];
long long numofone[41];

void fib(int n) {
	numofzero[0] = 1;
	numofzero[1] = 0;
	
	numofone[0] = 0;
	numofone[1] = 1;

	for (int i = 2; i <= n; i++) {
		numofzero[i] = numofzero[i - 1] + numofzero[i - 2];
		numofone[i] = numofone[i - 1] + numofone[i - 2];
	}
}

int main() {

	int tc;
	cin >> tc;
	
	while (tc--) {
		int N;
		cin >> N;
		fib(N);
		cout << numofzero[N] << " " << numofone[N] << "\n";
	}

	return 0;
}