#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int a1, b1;
	int a2, b2;
	int A, B;
	cin >> a1 >> b1;
	cin >> a2 >> b2;

	B = b1 * b2 / gcd(b1, b2);
	A = b2 / gcd(b1, b2) *a1 + b1 / gcd(b1, b2)*a2;
	
	int tmp = gcd(A, B);
	if (tmp > 1) {
		A /= tmp;
		B /= tmp;
	}

	cout << A << " " << B;
	return 0;
}