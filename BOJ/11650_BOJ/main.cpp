#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<pair<int, int>> coord;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}
	
	sort(coord.begin(), coord.end());

	for (int i = 0; i < N; i++) {
		cout << coord[i].first << " " << coord[i].second << "\n";
	}

	return 0;
}