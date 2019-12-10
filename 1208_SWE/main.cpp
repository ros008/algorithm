#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int test_case = 10;
	
	for (int tc = 1; tc <= test_case; tc++) {
		int dump;
		cin >> dump;

		vector<int> height(100);
		
		for (int i = 0; i < 100; i++) {
			cin >> height[i];
		}

		for (int i = 0; i < dump; i++) {
			sort(height.begin(), height.end());
			//for (int j = 0; j < 100; j++) cout << height[j] << " ";
			//cout << "\n";
			if (height[99] == height[0]) break;
			height[99]--;
			height[0]++;
		}

		sort(height.begin(), height.end());
	
		cout << "#" << tc << " " << (height[99] - height[0]) << "\n";
	}

	return 0;
}