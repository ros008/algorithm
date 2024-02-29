#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rope[100001];

bool desc(int a, int b) {
	return a > b;
}

void maxweight() {

	int maxvalue = 0;
	sort(rope, rope + N, desc);

	for (int i = 0; i < N; i++) {
		maxvalue = max(maxvalue, rope[i] * (i + 1));
	}

	cout << maxvalue;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}

	maxweight();

	return 0;
}