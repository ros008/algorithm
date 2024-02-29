#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	int num[10001] = { 0, };
	

	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num[tmp]++;
	}

	for (int i = 1; i < 10001; i++) {
		if (num[i] != 0) {
			for (int j = 0; j < num[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}