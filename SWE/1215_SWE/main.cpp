#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	for (int t = 1; t <= 10; t++) {
		int len;
		char arr[9][9];
		int cnt = 0;

		cin >> len;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (j + len <= 8) {
					bool flag = true;
					for (int a = j, b = j + len - 1; a < j + len / 2; a++, b--) {
						if (arr[i][a] != arr[i][b]) flag = false;
					}
					if (flag) cnt++;
				}
				if (i + len <= 8) {
					bool flag = true;
					for (int a = i, b = i + len - 1; a < i + len / 2; a++, b--) {
						if (arr[a][j] != arr[b][j]) flag = false;
					}
					if (flag) cnt++;
				}
			}
		}

		cout << "#" << t << " " << cnt << "\n";
	}


	return 0;
}