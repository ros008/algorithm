#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	long long T, n , m;
	cin >> T;

	cin >> n;
	vector<long long> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cin >> m;
	vector<long long> B(m);
	for (int i = 0; i < m; i++)
		cin >> B[i];

	long long sum;
	vector<long long> vA;
	for (int i = 0; i < n; i++) {
		sum = A[i];
		vA.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			vA.push_back(sum);
		}
	}
	sort(vA.begin(), vA.end());

	vector<long long> vB;
	for (int i = 0; i < m; i++) {
		sum = B[i];
		vB.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			vB.push_back(sum);
		}
	}
	sort(vB.begin(), vB.end());

	long long ans = 0;

	for (int i = 0; i < vA.size(); i++) {
		int low = lower_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();
		int high = upper_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();
		ans += high - low;
	}

	cout << ans;

	return 0;
}