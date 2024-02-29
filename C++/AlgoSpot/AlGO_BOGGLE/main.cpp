#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

char arr[5][5];
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				cin >> arr[i][j];
		
		cin >> N;

		for (int i = 0; i < N; i++) {

		}
	}

	return 0;
}