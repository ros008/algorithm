#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX = 1000001;

ll nums[MAX];
ll rev_gcd[MAX];
ll for_gcd[MAX];

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;
	ll max_gcd = 0;
	ll ex_num = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for_gcd[0] = nums[0];
	rev_gcd[0] = nums[n - 1];
	for (int i = 1; i < n; i++) {
		for_gcd[i] = gcd(for_gcd[i - 1], nums[i]);
		rev_gcd[i] = gcd(rev_gcd[i - 1], nums[n - i - 1]);
	}

	//for (int i = 0; i < n; i++) {
	//	cout << for_gcd[i] << " " << rev_gcd[i] << "\n";
	//}

	ll tmp;
	if (nums[0] < rev_gcd[n - 2] || gcd(nums[0], rev_gcd[n - 2]) != rev_gcd[n - 2]) {
		max_gcd = rev_gcd[n - 2];
		ex_num = nums[0];
	}

	for (int i = 0; i < n - 2; i++) {
		tmp = gcd(for_gcd[i], rev_gcd[n - 3 - i]);
		if (nums[i + 1] < tmp || gcd(nums[i + 1], tmp) != tmp) {
			if (tmp > max_gcd) {
				max_gcd = tmp;
				ex_num = nums[i + 1];
			}
		}
	}

	if (nums[n - 1] < for_gcd[n - 2] || gcd(nums[n - 1], for_gcd[n - 2]) != tmp) {
		if (tmp > max_gcd) {
			max_gcd = for_gcd[n - 2];
			ex_num = nums[n - 2];
		}
	}

	if (max_gcd == 0)
		cout << -1;
	else
		cout << max_gcd << " " << ex_num;


	
	return 0;
}