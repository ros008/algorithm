#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int map[1000001];
int arrB[500001];
long long tree[500000 * 4 + 1];

void update(int node, int s, int e, int diff, int index) {
	if (index < s || e < index)
		return;

	tree[node] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, diff, index);
		update(node * 2 + 1, mid + 1, e, diff, index);
	}
}

long long getSum(int node, int s, int e, int left, int right) {
	if (right < s || e < left)
		return 0;

	if (left <= s && e <= right)
		return tree[node];

	int mid = (s + e) / 2;

	return getSum(node * 2, s, mid, left, right) + getSum(node * 2 + 1, mid + 1, e, left, right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		map[val] = i;
	}
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arrB[i] = map[val];
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += getSum(1, 0, n - 1, arrB[i] + 1, n - 1);
		update(1, 0, n - 1, 1, arrB[i]);
	}

	cout << ans << "\n";

	return 0;
}