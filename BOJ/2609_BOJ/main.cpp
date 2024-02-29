#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int x, y; cin >> x >> y;

	cout << gcd(x, y) << '\n' <<  x * y / gcd(x, y) << '\n';

	return 0;
}