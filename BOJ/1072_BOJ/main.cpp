#include <iostream>
#include <cmath>

using namespace std;

long long X, Y, Z;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> X >> Y;

	Z = 100 * Y / X;

	if (Z >= 99) {
		cout << -1;
		return 0;
	}

	long long mid, new_z;
	long long low = 0, high = 1000000000;
	while (low <= high) {
		mid = (low + high) / 2;
		new_z = 100 * (Y + mid) / (X + mid);
		if (new_z > Z) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	
	cout << low;

	return 0;
}