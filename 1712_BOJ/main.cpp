#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	long long A, B, C;

	cin >> A >> B >> C;

	if (C - B <= 0) {
		cout << "-1" << "\n";
	}
	else {
		long long cminb = C - B;
		long long x = A / (C - B);
		cout << x + 1 << "\n";
	}


	return 0;
}