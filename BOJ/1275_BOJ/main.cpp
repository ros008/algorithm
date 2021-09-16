#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 1000001

using namespace std;

long long tree[MAX];

void update(int idx, int s, int e, int a, int b) {
	if (a < s || e < a) 
		return;

	if (s == e)	tree[idx] = b;
	else {
		int mid = (s + e) / 2;
		update(idx * 2, s, mid, a, b);
		update(idx * 2 + 1, mid + 1, e, a, b);
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

long long getSum(int idx, int s, int e, int l, int r) {
	if (r < s || e < l) 
		return 0;

	if (l <= s && e <= r) 
		return tree[idx];

	int mid = (s + e) / 2;
	return getSum(idx * 2, s, mid, l, r) + getSum(idx * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		int input;
		cin >> input;
		update(1, 1, n, i, input);
	}

	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) 
			cout << getSum(1, 1, n, y, x) << "\n";
		else
			cout << getSum(1, 1, n, x, y) << "\n";
		update(1, 1, n, a, b);
	}

	return 0;
}