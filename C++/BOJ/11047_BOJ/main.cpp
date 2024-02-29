#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int coin[11];
int result = 0;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + N, compare);

	for (int i = 0; i < N; i++) {
		result += K / coin[i];
		K %= coin[i];
	}

	cout << result << '\n';

	return 0;
}