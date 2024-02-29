#include <iostream>
#include <vector>

#define MAX 1000003

using namespace std;

int nums[MAX] = { 0, };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 2; i*i < MAX; i++) {
		if (nums[i] == 0) {
			for (int j = i * i; j < MAX; j += i) {
				nums[j]++;
			}
		}
	}

	while (1) {
		int n, i; 
		cin >> n;

		if (n == 0) break;

		bool chk = false;
		for (i = 3; i <= n / 2; i+=2) {
			//cout << nums[i] << " ";
			if (nums[i] == 0 && nums[n - i] == 0) {
				cout << n << " = " << i << " + " << n - i << "\n";
				chk = true;
				break;
			}
		}
		if (!chk) 
			cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}