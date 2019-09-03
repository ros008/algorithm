#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int len;
int table[101][101];
int result = 0;

int main() {

	for (int tc = 1; tc <= 10; tc++) {

		result = 0;

		cin >> len;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				cin >> table[i][j];
			}
		}

		for (int j = 0; j < len; j++) {
			int check = 0;
			for (int i = 0; i < len; i++) {
				if (table[i][j] == 0) {
					continue;
				}
				else if (table[i][j] == 1) {
					check = 1;
				}
				else if (table[i][j] == 2 && check == 0) {
					continue;
				}
				else if (table[i][j] == 2 && check == 1) {
					result++;
					check = 0;
				}
			}
		}


		cout << "#" << tc << " " << result << "\n";
	}

	return 0;
}