#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int arr[1001];
	int mincnt[1001];
	int maxlen = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		mincnt[i] = 1;

		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j] && mincnt[i] < mincnt[j] + 1) {
				mincnt[i] = mincnt[j] + 1;
			}
		}
		maxlen = max(maxlen, mincnt[i]);
	}

	cout << maxlen << "\n";

	return 0;
}