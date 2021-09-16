#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int up, down, total = 0, maxPeople = 0;

	for (int i = 0; i < 4; i++) {
		cin >> down >> up;
		total = total - down + up;
		maxPeople = max(maxPeople, total);
	}

	cout << maxPeople << "\n";

	return 0;
}