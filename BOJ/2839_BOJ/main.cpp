#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int result = -1;
	int flag = 0;

	cin >> N;

	if (N % 5 == 0) {
		result = N / 5;
	}
	else {
		for (int i = N / 5; i >= 0; i--) {
			int k = N - (i * 5);
			for (int j = k / 3; j >= 0; j--) {
				if (k % 3 == 0) {
					result = i + j;
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}