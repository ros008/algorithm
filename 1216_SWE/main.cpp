#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	for (int t = 1; t <= 10; t++) {
		char arr[101][101];
		int maxLen = 0;
		int tc;

		cin >> tc;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				for (int len = 1; i + len <= 100 || j + len <= 100; len++) {
					if (j + len <= 100) {
						bool flag = true;
						for (int a = j, b = j + len - 1; a < j + len / 2; a++, b--) {
							if (arr[i][a] != arr[i][b]) flag = false;
						}
						if (flag && maxLen < len) maxLen = len;
					}
					if (i + len <= 100) {
						bool flag = true;
						for (int a = i, b = i + len - 1; a < i + len / 2; a++, b--) {
							if (arr[a][j] != arr[b][j]) flag = false;
						}
						if (flag && maxLen < len) maxLen = len;
					}
				}
			}
		}

		cout << "#" << tc << " " << maxLen << "\n";
	}


	return 0;
}