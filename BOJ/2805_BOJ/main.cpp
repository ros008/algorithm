#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> treeArr;
int N, M;

bool possible(long long height) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (treeArr[i] > height) {
			sum = sum + (treeArr[i] - height);
		}
	}

	if (sum >= M) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;

	treeArr = vector<long long>(N);

	long long low = 1, high;
	long long maxHigh = 0;

	for (int i = 0; i < N; i++) {
		cin >> treeArr[i];
		high = max(high, treeArr[i]);
	}

	while (low <= high) {
		long long mid = (low + high) / 2;
		if (possible(mid)) {
			maxHigh = max(maxHigh, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << maxHigh;

	return 0;
}