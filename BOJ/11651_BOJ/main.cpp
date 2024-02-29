#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare (pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

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

	sort(coord.begin(), coord.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << coord[i].first << " " << coord[i].second << "\n";
	}

	return 0;
}

