#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;

	int two = 0;
	int five = 0;

	for (int i = N; i > 1; i--) {
		int tmp = i;
		while (tmp % 2 == 0) {
			two++;
			tmp /= 2;
		}
		while (tmp % 5 == 0) {
			five++;
			tmp /= 5;
		}
	}


	cout<<min(five, two);

	return 0;
}