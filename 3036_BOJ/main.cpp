#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ring[101];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ring[i];
	}

	for (int i = 1; i < N; i++) {
		int cd = gcd(ring[0], ring[i]);
		cout << ring[0] / cd << '/' << ring[i] / cd << '\n';
	}

	return 0;
}