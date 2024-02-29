#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N; cin >> N;
	vector<int> aliquot(N);

	for (int i = 0; i < N; i++) {
		cin >> aliquot[i];
	}

	sort(aliquot.begin(), aliquot.end());

	cout << aliquot[0] * aliquot[N - 1];


	return 0;
}