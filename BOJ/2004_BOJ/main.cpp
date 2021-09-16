#include <iostream>
#include <algorithm>

using namespace std;

long long i;

int countFive(int num) {
	int count = 0;
	
	for (i = 5; num / i >= 1; i *= 5) {
		count += num / i;
	}

	return count;
}

int countTwo(int num) {
	int count = 0;

	for (i = 2; num / i >= 1; i *= 2) {
		count += num / i;
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;
	int five = 0; 
	int two = 0;

	five += countFive(n);
	if (m != 0) five -= countFive(m);
	if (m != n) five -= countFive(n - m);

	two += countTwo(n);
	if (m != 0) two -= countTwo(m);
	if (m != n) two -= countTwo(n - m);
	
	cout << min(two, five);

	return 0;
}