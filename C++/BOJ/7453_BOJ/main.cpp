#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);
	vector<int> C(n);
	vector<int> D(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	//sort(A.begin(), A.end());
	//sort(B.begin(), B.end());
	//sort(C.begin(), C.end());
	//sort(D.begin(), D.end());

	vector<int> AB;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
		}
	}

	vector<int> CD;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	long long ans = 0;

	for (int i = 0; i < AB.size(); i++) {
		int low = lower_bound(CD.begin(), CD.end(), (-1)*AB[i]) - CD.begin();
		int high = upper_bound(CD.begin(), CD.end(), (-1)*AB[i]) - CD.begin();
		ans += high - low;
	}

	cout << ans;

	return 0;
}