#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;


int result[10 + 1][10 + 1];

int N, K;

int main() {

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) {
				result[i][j] = 1;
			}
			else {
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}
	}

	cout << result[N][K];

	return 0;
}