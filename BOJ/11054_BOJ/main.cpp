#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int arr[1001];
	int maxlen = 0;

	int incmaxlen[1001];
	int decmaxlen[1001];

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		incmaxlen[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && incmaxlen[i] < incmaxlen[j] + 1) {
				incmaxlen[i] = incmaxlen[j] + 1;
			}
		}
	}

	for (int i = N; i >= 1; i--) {
		decmaxlen[i] = 1;
		for (int j = N; j > i; j--) {
			if (arr[j] < arr[i] && decmaxlen[i] < decmaxlen[j] + 1) {
				decmaxlen[i] = decmaxlen[j] + 1;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		maxlen = max(maxlen, incmaxlen[i] + decmaxlen[i] - 1);
	}

	cout << maxlen;

	return 0;
}