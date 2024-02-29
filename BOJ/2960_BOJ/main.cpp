#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> nums(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		if (nums[i] == 0) { // 아직 체크안되었으면
			for (int j = i; j <= n; j += i) {
				if (nums[j] == 0) {
					k--;
				}
				nums[j]++;
				if (k == 0) {
					cout << j;
					return 0;
				}
			}
		}
	}

	return 0;
}