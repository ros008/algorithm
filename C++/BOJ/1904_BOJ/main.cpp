#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	int a = 0, b = 1, c;
	for (int i = 0; i < N; i++) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}
	
	cout << c;

	return 0;
}