#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mincnt[501];
int maxcnt = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> electro;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		electro.push_back(make_pair(a, b));
	}

	sort(electro.begin(), electro.end());

	for (int i = 0; i < N; i++) {
		mincnt[i] = 1;
		for (int j = 0; j < i; j++) {
			if (electro[j].second < electro[i].second) {
				mincnt[i] = max(mincnt[i], mincnt[j] + 1);
			}
		}
		maxcnt = max(maxcnt, mincnt[i]);
	}

	cout << N - maxcnt << '\n';

	return 0;
}