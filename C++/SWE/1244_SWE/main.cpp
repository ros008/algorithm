#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

string str;
int moveLimit;
int result = 0;
int check[1000000][2];

void dfs(int cnt) {
	if (cnt == moveLimit) {
		result = max(result, atoi(str.c_str()));
		return;
	}

	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[i] <= str[j]) {
				swap(str[i], str[j]);
				if (check[atoi(str.c_str())][cnt + 1] == 0) {
					check[atoi(str.c_str())][cnt + 1] = 1;
					dfs(cnt + 1);
				}
				swap(str[i], str[j]);
			}
		}
	}
}

int main() {

	int tc;

	cin >> tc;

	memset(check, 0, sizeof(check));

	for (int k = 1; k <= tc; k++) {

		cin >> str;
		cin >> moveLimit;

		result = 0;

		dfs(0);


		cout << "#" << k << " " << result << endl;
	}


	return 0;
}