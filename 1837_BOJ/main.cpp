#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1e6 + 3;

vector<int> prime;
bool chk[MAX]; //false: 소수 true: 소수 아님 
string p;
int k;

bool isMultiple(int x) {
	int rem = 0;
	for (int i = 0; p[i]; i++) {
		rem *= 10;
		rem += (p[i] - '0');
		rem %= x;
	}
	return rem == 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 2; i*i < MAX; i++) {
		if (!chk[i]) {
			prime.push_back(i);
			for (int j = i * i; j < MAX; j += i) {
				chk[j] = true;
			}
		}
	}

	cin >> p >> k;

	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] >= k) {
			break;
		}
		if (isMultiple(prime[i])) {
			cout << "BAD " << prime[i];
			return 0;
		}
	}
	
	cout << "GOOD";

	return 0;
}