#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4000001;

bool isprime[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= n; j += i) {
				isprime[j] = true;
			}
		}
	}

	int cnt = 0, sum;
	for (int i = 0; i < prime.size(); i++) {
		sum = 0;
		for (int j = i; j < prime.size(); j++) {
			sum += prime[j];
			if (sum > n) break;
			else if (sum == n) cnt++;
		}
	}

	cout << cnt;

	return 0;
}