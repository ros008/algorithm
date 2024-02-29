#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	vector<int> input(N);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	int sum = 0;
	int sssum = 0;

	for (int i = 0; i < N; i++) {
		sum += input[i];
		sssum += sum;
	}

	cout << sssum << '\n';

	return 0;
}