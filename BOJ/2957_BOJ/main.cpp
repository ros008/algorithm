#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int n;
ll c = 0;
map<int, int> depth;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		if (i == 0) {
			depth[input] = 1;
			cout << c << "\n";
			continue;
		}
		 
		auto iter = depth.upper_bound(input);
		int height = 0;

		// 제일 큰 숫자가 아니면
		if (iter != depth.end()) {
			height = iter->second;
		}

		if (iter != depth.begin()) {
			iter--;
			height = max(height, iter->second);
		}

		c += height;
		depth[input] = height + 1;

		cout << c << "\n";
	}

	return 0;
}