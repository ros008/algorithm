#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;

bool isPrime[MAX];
vector<int> prime;

void getPrime() {
	for (int i = 2; i <= MAX; i++) {
		if (!isPrime[i]) {
			prime.push_back(i);
			for (int j = i * i; j <= MAX; j += i)
				isPrime[j] = true;
		}
	}
}

int euler(int x) {
	int ret = 1;
	for (int i = 0; i < prime.size(); i++) {
		int tmp = 1;
		while (x % prime[i] == 0) {
			x /= prime[i];
			tmp *= prime[i];
		}
		ret *= (tmp - tmp / prime[i]);
	}
	if (x != 1) ret *= (x - 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int tc;
	cin >> tc;
	
	getPrime();

	int n, result;
	while (tc--) {
		cin >> n;
		result = 0;
		for (int i = 2; i <= n; i++) {
			//cout << "euler(" << i << ")" << ": " << euler(i) << "\n";
			result += euler(i);
		}

		result = result * 2 + 3;
		cout << result << "\n";
	}

	return 0;
}