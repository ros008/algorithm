#include <iostream>
#include <vector>

using namespace std;

int maxi[12][12];

int main() {

	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		vector<pair<int, int>> v;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> maxi[i][j];
				if (i == 0 || j == 0 || i == N - 1 || j == N - 1) continue;
				if (maxi[i][j] == 1) v.push_back(make_pair(i, j));
			}
		}
		




		cout << "#" << tc << " " << "\n";
	}

	return 0;
}