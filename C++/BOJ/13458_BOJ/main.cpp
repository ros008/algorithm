#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1000001];
int b, c;

long long result = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		a[i] -= b;
		result++;
		if (a[i] > 0) {
			if (a[i] % c == 0)
				result += (a[i] / c);
			else
				result += (a[i] / c) + 1;
		}
	}

	cout << result << "\n";

	return 0;
}