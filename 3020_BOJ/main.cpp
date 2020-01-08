#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 500001

using namespace std;

int seoksun[MAX];
int jongyu[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, h;
	int s, j;
	int sMax = 0;
	int jMax = 0;
	int minVal = 1000000;
	int cnt = 1;

	cin >> n >> h;

	for (int i = 0; i < n / 2; i++) {
		cin >> s >> j;
		seoksun[s]++;
		jongyu[j]++;
		if (s > sMax) sMax = s;
		if (j > jMax) jMax = j;
	}

	for (int i = sMax; i >= 1; i--) {
		seoksun[i] = seoksun[i] + seoksun[i + 1];
	}
	for (int i = jMax; i >= 1; i--) {
		jongyu[i] = jongyu[i] + jongyu[i + 1];
	}

	for (int i = 1; i <= h; i++) {
		if (seoksun[i] + jongyu[h - i + 1] < minVal) {
			minVal = seoksun[i] + jongyu[h - i + 1];
			cnt = 1;
		}
		else if (seoksun[i] + jongyu[h - i + 1] == minVal) {
			cnt++;
		}
	}
	
	cout << minVal << " " << cnt << "\n";

	return 0;
}